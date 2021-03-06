//
// Created by Mikel Matticoli on 2/16/18.
//

#include "SortedEventQueue.h"

/**
 * Adds event to queue sorted by start time
 * @param e Pointer to event to add to queue
 */
void SortedEventQueue::add(Event *e) {
    // If no root
    if(this->root == nullptr) {
        // Set Event as root
        this->root = e;
        return;
    } else if (e->startTime <= root->startTime) {
        // If this should be first, put it there
        e->next = root;
        root = e;
        return;
    }
    // else, insert in correct spot
    Event *n = root;
    while(n->next != nullptr && e->startTime >= n->next->startTime) {
        n = n->next;
    }
    e->next = n->next;
    n->next = e;
}
