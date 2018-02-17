//
// Created by Mikel Matticoli on 2/14/18.
//

#ifndef ASSIGNMENT4_EVENT_H
#define ASSIGNMENT4_EVENT_H

#include <iostream>

class Event {

    public:
        /**
         * Pointer to next event in EventQueue
         */
        Event *next = nullptr;
        /**
         * Start time of event in minutes
         */
        double startTime;

        Event(double startTime);
        virtual std::string getType();
        std::string toString();
};


#endif //ASSIGNMENT4_EVENT_H
