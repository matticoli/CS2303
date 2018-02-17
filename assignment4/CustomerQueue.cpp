//
// Created by student on 2/15/18.
//

#include "CustomerQueue.h"


CustomerQueue* CustomerQueue::shortestCustomerQueue;

CustomerQueue::CustomerQueue() {
    shortestCustomerQueue = this;
}

void CustomerQueue::add(Event *e) {
    if(e->getType() == "Customer") {
        EventQueue::add(e);
    }

//    if(shortestCustomerQueue == nullptr || length() <  shortestCustomerQueue->length()) {
//        shortestCustomerQueue = this;
//    }
}

CustomerEvent *CustomerQueue::peek() {
    return static_cast<CustomerEvent *>(EventQueue::peek());
}

CustomerEvent *CustomerQueue::pop() {
    return static_cast<CustomerEvent *>(EventQueue::pop());
}