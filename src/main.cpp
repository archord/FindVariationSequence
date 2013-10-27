/* 
 * File:   main.cpp
 * Author: xy
 *
 * Created on October 21, 2013, 10:04 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "FindVariationSequence.h"
//#include "utils.h"
//#include "CircleList.h"

void printHelp();

int main(int argc, char** argv) {

    if (argc < 9) {
        printHelp();
        return 1;
    }

    float errorBox = atof(argv[4]);
    int prevN = atoi(argv[7]);
    float rmsTimes = atof(argv[8]);
    FindVariationSequence *varseq = new FindVariationSequence();
    varseq->batchMatch(argv[1], argv[2], argv[3], errorBox, argv[5],
            argv[6], prevN, rmsTimes);
    //printf("%.8f\n", varseq->getImageTime("20130111_177d550752_60d851283-420.fit"));

//    CircleList *clst = new CircleList(5);
//    float tmp[] = {3, 4, 7, 2, 7, 4, 9, 6, 1, 8, 5, 9,6,3,5};
//    for (int i = 0; i < 15; i++) {
//        clst->add(tmp[i]);
//        printf("%f sum=%.2f avg=%.2f ", tmp[i], clst->getSum(), clst->getAvg());
//        printf("rms=%f\n", clst->getRms());
//    }


    return 0;
}

void printHelp() {
    printf("Usage:\n");
    printf("\tcrossmatch reffName stdfName objListfName errorBox outDir1 outDir2 prevN rmsTimes\n");
    printf("\tcrossmatch data/referance.cat data/standrad.cat data/objfilelist.cat 0.7 result result2 30 3\n");
}