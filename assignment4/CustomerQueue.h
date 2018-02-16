//
// Created by student on 2/15/18.
//

#ifndef ASSIGNMENT4_CUSTOMERQUEUE_H
#define ASSIGNMENT4_CUSTOMERQUEUE_H


#include "EventQueue.h"
#include "CustomerEvent.h"

class CustomerQueue : public EventQueue {
    void add(Event *e) override;
    CustomerEvent *peek();
    CustomerEvent *pop();
};


#endif //ASSIGNMENT4_CUSTOMERQUEUE_H
