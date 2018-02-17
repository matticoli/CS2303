//
// Created by student on 2/15/18.
//

#include "TellerEvent.h"

TellerEvent::TellerEvent(double startTime, double duration, TEventType eventType, CustomerQueue *queue) : Event(startTime, duration) {
    this->eventType = eventType;
    this->queue = queue;
}

void TellerEvent::retask(double startTime, double duration, TEventType eventType) {
    this->startTime = startTime;
    this->duration = duration;
    this->eventType = eventType;
}

std::string TellerEvent::getType() {
    return "Teller";
}
