//
// Created by student on 2/15/18.
//

#include "CustomerEvent.h"

CustomerEvent::CustomerEvent(double startTime, double duration, CEventType eventType) : Event(startTime, duration) {
    this->eventType = eventType;
    if(eventType == ARRIVE) {
        this->arrivalTime = startTime;
    }
}

void CustomerEvent::retask(double startTime, double duration, CEventType eventType) {
    this->startTime = startTime;
    this->duration = duration;
    this->eventType = eventType;
}

std::string CustomerEvent::getType() {
    return "Customer";
}
