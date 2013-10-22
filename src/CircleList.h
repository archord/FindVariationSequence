/* 
 * File:   CircleList.h
 * Author: xy
 *
 * Created on October 22, 2013, 8:54 PM
 */

#ifndef CIRCLELIST_H
#define	CIRCLELIST_H

typedef struct CIRCLE_LIST{
    float value;
    struct CIRCLE_LIST *prev;
    struct CIRCLE_LIST *next;
} circle_lst;

class CircleList {
public:
    CircleList();
    CircleList(const CircleList& orig);
    virtual ~CircleList();
private:
    int length;
    float total;
    float avg;
    float rms;
    circle_lst *head;
    circle_lst *tail;
    circle_lst *cur;

};

#endif	/* CIRCLELIST_H */

