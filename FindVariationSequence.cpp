/* 
 * File:   FindVariationSequence.cpp
 * Author: xy
 * 
 * Created on October 21, 2013, 10:11 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "FindVariationSequence.h"

FindVariationSequence::FindVariationSequence() {
}

FindVariationSequence::FindVariationSequence(const FindVariationSequence& orig) {
}

FindVariationSequence::~FindVariationSequence() {
}

void FindVariationSequence::batchMatch(char *reffName, char *stdfName,
        char *objListfName, float errorBox, char *vsOutDir, char *outDir2,
        int avgN, int trms) {

    printf("starting match...\n");

    int i = 0;
    int stdStarNum = 0;
    int refStarNum = 0;
    cm_star *std = readStdFile(stdfName, stdStarNum);
    cm_star *ref = readRefFile(reffName, refStarNum);
    matchStandradStar(std, ref, errorBox);

    /**/
    int objFileNum = 0;
    char **objfNames = getAllObjFileName(objListfName, objFileNum);

    vs_result *vsRst = (vs_result *) malloc(sizeof (vs_result) * refStarNum);
    cm_star *nextStar = ref;
    int objIdx = 0;
    while (nextStar) {
        vsRst[objIdx].refX = nextStar->pixx;
        vsRst[objIdx].refY = nextStar->pixy;
        vsRst[objIdx].refmag = nextStar->mag;
        vsRst[objIdx].stdX = nextStar->match->pixx;
        vsRst[objIdx].stdY = nextStar->match->pixy;
        vsRst[objIdx].stdmag = nextStar->match->mag;
        vsRst[objIdx].rcdlst = (match_mag_rcd *) malloc(sizeof (match_mag_rcd) * objFileNum);
        vsRst[objIdx].rcdNum = 0;
        objIdx++;
        nextStar = nextStar->next;
    }

    float minZoneLen = errorBox * TimesOfErrorRadius;
    float searchRds = errorBox;
    Partition *refZones = new Partition(errorBox, minZoneLen, searchRds);
    Partition *objZones = new Partition(errorBox, minZoneLen, searchRds);
    refZones->partitonStarField(ref, refStarNum);
    ref = NULL;

    for (i = 0; i < objFileNum; i++) {
        int objStarNum = 0;
        cm_star *obj = readObjFile(objfNames[i], objStarNum);
        cm_star *obj2 = copyStarList(obj);
        objZones->partitonStarField(obj2, refStarNum);
        obj2 = NULL;
        nextStar = obj;
        while (nextStar) {
            refZones->getMatchStar(nextStar);
            nextStar = nextStar->next;
        }
        /*print match result or OT*/

        nextStar = obj;
        while (nextStar) {
            if (NULL != nextStar->match && nextStar->mag < MAX_MAG) {
                cm_star *tRefStar = nextStar->match;
                cm_star *tStdStar = tRefStar->match;
                objZones->getMatchStar(tStdStar);
                if (NULL != tStdStar->match) {
                    long curMatchCnt = vsRst[tRefStar->id].rcdNum;
                    match_mag_rcd *curMatchPeer = vsRst[tRefStar->id].rcdlst;
                    curMatchPeer[curMatchCnt].time = 0;
                    curMatchPeer[curMatchCnt].refMchMag = nextStar->mag;
                    curMatchPeer[curMatchCnt].refMchMagErr = nextStar->mage;
                    curMatchPeer[curMatchCnt].stdMchMag = tStdStar->match->mag;
                    curMatchPeer[curMatchCnt].stdMchMagErr = tStdStar->match->mage;
                    vsRst[nextStar->match->id].rcdNum++;
                }
            }
            nextStar = nextStar->next;
        }
        freeStarList(obj);
        objZones->freeZoneArray();
        //if (objFileNum % 100 == 1)
        printf("done %dth star list\n", i+1);
    }
    refZones->freeZoneArray();

    printf("match All file done, starting write result to file...\n");
    
    int newFileCount = 0;
    char *outfName = (char *) malloc(sizeof (char)*MaxStringLength);
    for (i = 0; i < refStarNum; i++) {
        if (0 != vsRst[i].rcdNum) {
            sprintf(outfName, "%s/abc_%f_%f_%.3f.cat", vsOutDir, vsRst[i].refX, vsRst[i].refY, vsRst[i].refmag);
            FILE *fp = fopen(outfName, "w");
            fprintf(fp, "#reference star x\n");
            fprintf(fp, "#reference star y\n");
            fprintf(fp, "#reference star mag\n");
            fprintf(fp, "#standrad star x\n");
            fprintf(fp, "#standrad star y\n");
            fprintf(fp, "#standrad star mag\n");
            fprintf(fp, "%f\n", vsRst[i].refX);
            fprintf(fp, "%f\n", vsRst[i].refY);
            fprintf(fp, "%f\n", vsRst[i].refmag);
            fprintf(fp, "%f\n", vsRst[i].stdX);
            fprintf(fp, "%f\n", vsRst[i].stdY);
            fprintf(fp, "%f\n", vsRst[i].stdmag);
            fprintf(fp, "\n");
            fprintf(fp, "#total star: %d\n", vsRst[i].rcdNum);
            fprintf(fp, "#time\trefMatchMag\trefMatchMagErr\tstdMatchMag\tstdMatchMagErr\n");


            long curMatchCnt = vsRst[i].rcdNum;
            match_mag_rcd *curMatchPeer = vsRst[i].rcdlst;
            int j;
            for (j = 0; j < curMatchCnt; j++) {
                fprintf(fp, "%f\t%f\t%f\t%f\t%f\n", curMatchPeer[j].time,
                        curMatchPeer[j].refMchMag, curMatchPeer[j].refMchMagErr,
                        curMatchPeer[j].stdMchMag, curMatchPeer[j].refMchMagErr);
            }
            fclose(fp);
            newFileCount ++;
        }
    }
    printf("total generate %d variation sequence file\n", newFileCount);

    free(outfName);
    freeAllFileName(objfNames, objFileNum);

    for (i = 0; i < refStarNum; i++) {
        free(vsRst[i].rcdlst);
    }
    free(vsRst);

    freeStarList(std);
    freeStarList(ref);
    printf("write file done\n");

}

char **FindVariationSequence::getAllObjFileName(char *fName, int &fileNum) {

    fileNum = countFileLines(fName);

    FILE *fp = fopen(fName, "r");

    if (fp == NULL) {
        return NULL;
    }

    char **fNames = (char **) malloc(sizeof (char*)*fileNum);
    char line[MaxStringLength];
    int i = 0;
    while (fscanf(fp, "%s", line) != EOF) {
        if (0 != strlen(line)) {
            fNames[i] = (char*) malloc(sizeof (char)*(strlen(line) + 1));
            strcpy(fNames[i], line);
            i++;
        }
    }
    return fNames;
}

void FindVariationSequence::freeAllFileName(char **objfNames, int fileNum) {
    int i;
    for (i = 0; i < fileNum; i++) {
        free(objfNames[i]);
    }
    free(objfNames);
}

void FindVariationSequence::matchStandradStar(cm_star *ref, cm_star *obj, float errorBox) {

    cm_star *tObj = obj;

    while (tObj) {
        float tError = 0.0;
        float minError = 0.0;
        cm_star *tRef = ref;
        while (tRef) {
            float xdiff = fabs(tRef->pixx - tObj->pixx);
            if (xdiff > DiffStarDistance) {
                minError = getLineDistance(tRef, tObj);
                tObj->match = tRef;
                tObj->error = minError;
                tRef = tRef->next;
                break;
            }
            tRef = tRef->next;
        }
        while (tRef) {
            float xdiff = fabs(tRef->pixx - tObj->pixx);
            if (xdiff > DiffStarDistance) {
                tError = getLineDistance(tRef, tObj);
                if (tError < minError) {
                    minError = tError;
                    tObj->match = tRef;
                    tObj->error = tError;
                }
            }
            tRef = tRef->next;
        }
        tObj = tObj->next;
    }
}

cm_star *FindVariationSequence::readObjFile(char *fName, int &starNum) {

    FILE *fp = fopen(fName, "r");
    if (fp == NULL) {
        return NULL;
    }

    starNum = 0;
    cm_star *starList = NULL;
    cm_star *tStar = NULL;
    cm_star *nextStar = NULL;
    char line[MaxStringLength];

    if (fgets(line, MaxStringLength, fp) != NULL) {
        nextStar = (cm_star *) malloc(sizeof (cm_star));
        nextStar->next = NULL;
        sscanf(line, "%f%f%*f%*f%*f%*f%f%f", &nextStar->pixx, &nextStar->pixy, &nextStar->mag, &nextStar->mage);
        starList = nextStar;
        tStar = nextStar;
        starNum++;
    }

    while (fgets(line, MaxStringLength, fp) != NULL) {
        nextStar = (cm_star *) malloc(sizeof (cm_star));
        nextStar->next = NULL;
        sscanf(line, "%f%f%*f%*f%*f%*f%f%f", &nextStar->pixx, &nextStar->pixy, &nextStar->mag, &nextStar->mage);
        tStar->next = nextStar;
        tStar = nextStar;
        starNum++;
    }

#ifdef PRINT_CM_DETAIL
    printf("%s\t%d stars\n", fName, starNum);
#endif
    return starList;
}

cm_star *FindVariationSequence::readRefFile(char *fName, int &starNum) {

    return readStarFile(fName, starNum);
}

cm_star *FindVariationSequence::readStdFile(char *fName, int &starNum) {

    return readStarFile(fName, starNum);
}