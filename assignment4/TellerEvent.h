//
// Created by student on 2/15/18.
//

#ifndef ASSIGNMENT4_TELLEREVENT_H
#define ASSIGNMENT4_TELLEREVENT_H


#include "Event.h"
#include "CustomerQueue.h"

enum TEventType { SERVE, IDLE };

class TellerEvent : public Event {
    public:
        TEventType eventType;
        CustomerQueue *queue;

        TellerEvent(double startTime, double duration, TEventType eventType, CustomerQueue *queue);
        void retask(double startTime, double duration, TEventType eventType);
        std::string getType() override;
};


#endif //ASSIGNMENT4_TELLEREVENT_H
