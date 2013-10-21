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

void printHelp();


int main(int argc, char** argv) {
    
    if (argc < 6){
        printHelp();
        return 1;
    }
    
    float errorBox = atof(argv[4]);
    FindVariationSequence *varseq = new FindVariationSequence();
    varseq->batchMatch(argv[1], argv[2], argv[3], errorBox, argv[5]);
    
    return 0;
}

void printHelp() {
    printf("Usage:\n");
    printf("\tcrossmatch reffName stdfName objListfName errorBox outputDirectory\n");
    printf("\tcrossmatch data/referance.cat data/standrad.cat data/objfilelist.cat 0.6 result\n");
}