//
// Created by Mikel Matticoli on 2/15/18.
//

#include "TellerEvent.h"

/**
 * Creates new TellerEvent
 * @param startTime start time for new event
 * @param queue TellerQueue to pull from
 */
TellerEvent::TellerEvent(double startTime, TellerQueue *queue) : Event(startTime) {
    this->queue = queue;
}

/**
 * Changes the start time and event type for teller event
 * @param startTime start time for new event
 */
void TellerEvent::retask(double startTime) {
    this->startTime = startTime;
}

/**
 * Returns a string corresponding to the event type
 * @return string corresponding to the event type
 */
std::string TellerEvent::getType() {
    return "Teller";
}
