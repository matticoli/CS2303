//
// Created by Mikel Matticoli on 2/16/18.
//

#ifndef ASSIGNMENT4_SORTEDEVENTQUEUE_H
#define ASSIGNMENT4_SORTEDEVENTQUEUE_H

#include <queue>
#include "EventQueue.h"

class SortedEventQueue {
    protected:
        std::priority_queue<Event *> *queue;
    public:
        SortedEventQueue();
        virtual void add(Event *e);
        virtual Event *peek();
        virtual Event *pop();
        int length();
        void print();
};


#endif //ASSIGNMENT4_SORTEDEVENTQUEUE_H
