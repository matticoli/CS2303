//
// Created by Mikel Matticoli on 2/16/18.
//

#ifndef ASSIGNMENT4_SORTEDEVENTQUEUE_H
#define ASSIGNMENT4_SORTEDEVENTQUEUE_H


#include "EventQueue.h"

class SortedEventQueue : public EventQueue {
public:
    void add(Event *e) override;
};


#endif //ASSIGNMENT4_SORTEDEVENTQUEUE_H
