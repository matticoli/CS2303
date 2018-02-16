//
// Created by student on 2/14/18.
//

#ifndef ASSIGNMENT4_LINKEDLIST_H
#define ASSIGNMENT4_LINKEDLIST_H


#include "Event.h"

class EventQueue {
protected:
    Event *root = nullptr;
public:
        virtual void add(Event *e);
        Event *peek();
        Event *pop();

//        std::string toString();

};


#endif //ASSIGNMENT4_LINKEDLIST_H
