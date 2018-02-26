//
// Created by Mikel Matticoli on 2/14/18.
//
#include <iostream>

#include "Event.h"

/**
 * Default constructor for event
 * @param startTime Event timestamp (minutes)
 */
Event::Event(double startTime) {
    this->startTime = startTime;
}

/**
 * Returns a string corresponding to the event type
 * @return string corresponding to the event type
 */
std::string Event::getType() {
    return "Event";
}

/**
 * Returns a string representation of the event
 * @return string representation of the event
 */
std::string Event::toString() {
    return getType() + "{" + std::to_string(startTime) + "}";
}

bool Event::operator<(const Event *b) {
    return startTime < b->startTime;
}