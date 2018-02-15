//
// Created by student on 2/15/18.
//

#include "TellerEvent.h"

TellerEvent::TellerEvent(double startTime, double duration, TEventType eventType) : Event(startTime, duration) {
    this->eventType = eventType;
}

void TellerEvent::retask(double startTime, double duration, TEventType eventType) {
    this->startTime = startTime;
    this->duration = duration;
    this->eventType = eventType;
}

char *TellerEvent::getType() {
    return const_cast<char *>("Teller");
}
