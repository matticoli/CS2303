//
// Created by student on 2/15/18.
//

#ifndef ASSIGNMENT4_CUSTOMEREVENT_H
#define ASSIGNMENT4_CUSTOMEREVENT_H


#include "Event.h"

enum CEventType { ARRIVE, WAIT, SERVED };

class CustomerEvent : public Event {
    public:
        CEventType eventType;
        double arrivalTime;

        CustomerEvent(double startTime, double duration, CEventType eventType);
        void retask(double startTime, double duration, CEventType eventType);
        char *getType() override;
    };


#endif //ASSIGNMENT4_CUSTOMEREVENT_H
