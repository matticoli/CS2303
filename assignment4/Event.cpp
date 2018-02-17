//
// Created by student on 2/14/18.
//
#include <iostream>

#include "Event.h"

Event::Event(double startTime, double duration) {
    this->startTime = startTime;
    this->duration = duration;
}

std::string Event::getType() {
    return "Event";
}

std::string Event::toString() {
    return getType() + "{" + std::to_string(startTime) + ", " + std::to_string(duration) + "}";
}
