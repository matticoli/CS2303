//
// Created by student on 2/14/18.
//

#ifndef ASSIGNMENT4_LINKEDLIST_H
#define ASSIGNMENT4_LINKEDLIST_H


#include "Event.h"

class EventQueue {
    Event *root = nullptr;
    public:
        void add(Event &e);
        Event *peek();
        Event *pop();
};


#endif //ASSIGNMENT4_LINKEDLIST_H
