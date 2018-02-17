//
// Created by Mikel Matticoli on 2/15/18.
//

#ifndef ASSIGNMENT4_CUSTOMEREVENT_H
#define ASSIGNMENT4_CUSTOMEREVENT_H


#include "Event.h"

/**
 * Enum for CustomerEvent type
 */
enum CEventType { ARRIVE, WAIT, SERVED };

class CustomerEvent : public Event {
    public:
        /**
         * Type of event (Arrive, Wait, or Served)
         */
        CEventType eventType;
        /**
         * Customer arrival time in minutes (for calculating stats)
         */
        double arrivalTime;

        CustomerEvent(double startTime, CEventType eventType);
        void retask(double startTime, CEventType eventType);
        std::string getType() override;
    };


#endif //ASSIGNMENT4_CUSTOMEREVENT_H
