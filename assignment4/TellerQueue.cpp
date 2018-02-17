//
// Created by Mikel Matticoli on 2/15/18.
//

#include "TellerQueue.h"


TellerQueue* TellerQueue::shortestTellerQueue;

/**
 * Creates an empty TellerQueue and marks it as the shortest
 */
TellerQueue::TellerQueue() {
    shortestTellerQueue = this;
}

/**
 * Adds event to queue ONLY if it is a CustomerEvent
 * @param e Pointer to event to add to queue
 */
void TellerQueue::add(Event *e) {
    if(e->getType() == "Customer") {
        EventQueue::add(e);
    }

    if(shortestTellerQueue == nullptr || length() <  shortestTellerQueue->length()) {
        shortestTellerQueue = this;
    }
}

/**
 * Returns head node of queue without removing it
 * @return first event in queue
 */
CustomerEvent *TellerQueue::peek() {
    return static_cast<CustomerEvent *>(EventQueue::peek());
}

/**
 * Removes head node from queue and returns it
 * @return fist event in queue
 */
CustomerEvent *TellerQueue::pop() {
    return static_cast<CustomerEvent *>(EventQueue::pop());
}