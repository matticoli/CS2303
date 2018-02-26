//
// Created by Mikel Matticoli on 2/14/18.
//

#ifndef ASSIGNMENT4_LINKEDLIST_H
#define ASSIGNMENT4_LINKEDLIST_H

#include <queue>
#include "Event.h"


class EventQueue {
protected:
    std::queue<Event *> *queue;
public:
    EventQueue();

    virtual void add(Event *e);
    virtual Event *peek();
    virtual Event *pop();
    int length();
    void print();
};


#endif //ASSIGNMENT4_LINKEDLIST_H
