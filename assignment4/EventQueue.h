//
// Created by Mikel Matticoli on 2/14/18.
//

#ifndef ASSIGNMENT4_LINKEDLIST_H
#define ASSIGNMENT4_LINKEDLIST_H


#include "Event.h"

class EventQueue {
protected:
    Event *root = nullptr;
public:
    virtual void add(Event *e);
    virtual Event *peek();
    virtual Event *pop();
    int length();
    void print();
};


#endif //ASSIGNMENT4_LINKEDLIST_H
