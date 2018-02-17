//
// Created by student on 2/15/18.
//

#ifndef ASSIGNMENT4_CUSTOMERQUEUE_H
#define ASSIGNMENT4_CUSTOMERQUEUE_H


#include "EventQueue.h"
#include "CustomerEvent.h"

class CustomerQueue : public EventQueue {
    public:
        CustomerQueue();
        static CustomerQueue *shortestCustomerQueue;
        void add(Event *e) override;
        CustomerEvent *peek() override;
        CustomerEvent *pop() override;
};


#endif //ASSIGNMENT4_CUSTOMERQUEUE_H
