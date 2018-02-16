//
// Created by student on 2/14/18.
//
#include <iostream>

#include "Event.h"

Event::Event(double startTime, double duration) {
    this->startTime = startTime;
    this->duration = duration;
}

char *Event::getType() {
    return const_cast<char *>("Event");
}

std::string Event::toString() {
    return "Event {" + std::to_string(startTime) + ", " + std::to_string(duration) + "}";
}
