//
// Created by Mikel Matticoli on 2/15/18.
//

#include "CustomerEvent.h"

/**
 * Creates new CustomerEvent
 * @param startTime start time for new event
 * @param eventType type of event (enum)
 */
CustomerEvent::CustomerEvent(double startTime, CEventType eventType) : Event(startTime) {
    this->eventType = eventType;
    // If creating arrival event, set customer arrival time
    if(eventType == ARRIVE) {
        this->arrivalTime = startTime;
    }
}

/**
 * Changes the start time and event type for customer event
 * @param startTime start time for new event
 * @param eventType type for new event (enum)
 */
void CustomerEvent::retask(double startTime, CEventType eventType) {
    this->startTime = startTime;
    this->eventType = eventType;
}

/**
 * Returns a string corresponding to the event type
 * @return string corresponding to the event type
 */
std::string CustomerEvent::getType() {
    return "Customer";
}

/**
 * Destructor
 */
CustomerEvent::~CustomerEvent() {
    // Nothing to delete, implemented to suppress compiler warning
}
