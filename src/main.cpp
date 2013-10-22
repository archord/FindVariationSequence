/* 
 * File:   main.cpp
 * Author: xy
 *
 * Created on October 21, 2013, 10:04 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "FindVariationSequence.h"
#include <stdio.h>
#include "utils.h"

void printHelp();


int main(int argc, char** argv) {
    
    if (argc < 6){
        printHelp();
        return 1;
    }
    
    float errorBox = atof(argv[4]);
    FindVariationSequence *varseq = new FindVariationSequence();
    varseq->batchMatch(argv[1], argv[2], argv[3], errorBox, argv[5]);

    
//    const char *jdStr="2013-01-11T18:26:22";
//    double ddate1 = calJulianDay(jdStr);
//    printf("time=%f\n", ddate1);
//    
//    char jdStr2[128];
//    char *fitsName = "20130111_177d550752_60d851283-420.fit";
//    char *attrName = "DATE-OBS";
//    readFitsAttrStr(fitsName, attrName, jdStr2);
//    double ddate2 = calJulianDay(jdStr2);
//    printf("time=%f\n", ddate2);
    
    return 0;
}

void printHelp() {
    printf("Usage:\n");
    printf("\tcrossmatch reffName stdfName objListfName errorBox outputDirectory\n");
    printf("\tcrossmatch data/referance.cat data/standrad.cat data/objfilelist.cat 0.6 result\n");
}