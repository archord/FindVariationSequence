/* 
 * File:   FindVariationSequence.h
 * Author: xy
 *
 * Created on October 21, 2013, 10:11 AM
 */

#ifndef FINDVARIATIONSEQUENCE_H
#define	FINDVARIATIONSEQUENCE_H

#include "CrossMatch.h"

typedef struct MATCH_MAG_RECORD {
    float time;
    float refMchMag;
    float refMchMagErr;
    float stdMchMag;
    float stdMchMagErr;
} match_mag_rcd;


typedef struct VS_RESULT {
    float refX;
    float refY;
    float refmag;
    float stdX;
    float stdY;
    float stdmag;
    match_mag_rcd *rcdlst;
    long rcdNum;
} vs_result;

#define MAX_MAG 30
#define OUTFILE_PREFIX "glc"

class FindVariationSequence : CrossMatch {
public:
    FindVariationSequence();
    FindVariationSequence(const FindVariationSequence& orig);
    virtual ~FindVariationSequence();
    cm_star *readObjFile(char *fName, int &starNum);
    cm_star *readRefFile(char *fName, int &starNum);
    cm_star *readStdFile(char *fName, int &starNum);

    void batchMatch(char *reffName, char *stdfName, char *objListfName, float errorBox, char *outDir);
    
private:
    static const int DiffStarDistance = 3;
    static const int DiffStarDistance1 = 3;

    char **getAllObjFileName(char *fName, int &fileNum);
    char **getAllObjFileName(char *fName);
    void freeAllFileName(char **objfNames, int fileNum);
    void matchStandradStar(cm_star *ref, cm_star *obj, float errorBox);
};

#endif	/* FINDVARIATIONSEQUENCE_H */

