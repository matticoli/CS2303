//
// Created by student on 2/15/18.
//

#ifndef ASSIGNMENT4_TELLEREVENT_H
#define ASSIGNMENT4_TELLEREVENT_H


#include "Event.h"

enum TEventType { SERVE, IDLE };

class TellerEvent : public Event {
    public:
        TEventType eventType;

        TellerEvent(double startTime, double duration, TEventType eventType);
        void retask(double startTime, double duration, TEventType eventType);
        char *getType() override;
};


#endif //ASSIGNMENT4_TELLEREVENT_H
