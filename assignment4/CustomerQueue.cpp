//
// Created by student on 2/15/18.
//

#include "CustomerQueue.h"
#include "EventQueue.h"
#include "Event.h"

void CustomerQueue::add(Event *e) {
    if(e->getType() == "Customer") {
        EventQueue::add(e);
    }
}

CustomerEvent *CustomerQueue::peek() {
    return static_cast<CustomerEvent *>(EventQueue::peek());
}

CustomerEvent *CustomerQueue::pop() {
    return static_cast<CustomerEvent *>(EventQueue::pop());
}
