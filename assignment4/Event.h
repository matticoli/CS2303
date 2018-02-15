//
// Created by Mikel Matticoli on 2/14/18.
//

#ifndef ASSIGNMENT4_EVENT_H
#define ASSIGNMENT4_EVENT_H

#include <iostream>

class Event {

    public:
        Event *next;
        double startTime, duration;

        Event(double startTime, double duration);
        virtual char *getType();
        std::string toString();
};


#endif //ASSIGNMENT4_EVENT_H
