//
// Created by Mikel Matticoli on 2/15/18.
//

#ifndef ASSIGNMENT4_TELLEREVENT_H
#define ASSIGNMENT4_TELLEREVENT_H


#include "Event.h"
#include "TellerQueue.h"

class TellerEvent : public Event {
    public:
        /**
         * TellerQueue to serve customers from
         */
        TellerQueue *queue;

        TellerEvent(double startTime, TellerQueue *queue);
        void retask(double startTime);
        std::string getType() override;
};


#endif //ASSIGNMENT4_TELLEREVENT_H
