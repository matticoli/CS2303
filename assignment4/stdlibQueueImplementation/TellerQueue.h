//
// Created by Mikel Matticoli on 2/15/18.
//

#ifndef ASSIGNMENT4_CUSTOMERQUEUE_H
#define ASSIGNMENT4_CUSTOMERQUEUE_H


#include "EventQueue.h"
#include "CustomerEvent.h"

class TellerQueue : public EventQueue {
    public:
        /**
         * Pointer to instance of TellerQueue with fewest CustomerEvents
         */
        static TellerQueue *shortestTellerQueue;

        TellerQueue();
        void add(Event *e) override;
        CustomerEvent *peek() override;
        CustomerEvent *pop() override;
};


#endif //ASSIGNMENT4_CUSTOMERQUEUE_H
