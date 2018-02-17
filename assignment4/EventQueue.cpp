//
// Created by Mikel Matticoli on 2/14/18.
//

#include "EventQueue.h"

/**
 * Adds event to queue
 * @param e Pointer to event to add to queue
 */
void EventQueue::add(Event *e) {
    // If no root
    if(!this->root) {
        // Set Event as root
        this->root = e;
        e->next = nullptr;
        return;
    }
    // else, find tail
    Event *tail = root;
    while(tail->next != nullptr) {
        tail = tail->next;
    }
    e->next = nullptr;
    tail->next = e;
}

/**
 * Returns head node of queue without removing it
 * @return first event in queue
 */
Event * EventQueue::peek() {
    return root;
}

/**
 * Removes head node from queue and returns it
 * @return fist event in queue
 */
Event * EventQueue::pop() {
    Event *n = root;
    root = root->next;
    n->next = nullptr;
    return n;
}

/**
 * Calculates length of queue
 * @return number of events in queue
 */
int EventQueue::length() {
    int count = 0;
    for(Event *n = root; n->next != nullptr; n++) count++;
    return count;
}

/**
 * Prints string representation of queue to std::cout
 */
void EventQueue::print() {
    std::cout << "Event Queue" << std::endl;
    Event *e = root;
    while(e) {
        std::cout << "\t" << e->toString() << std::endl;
        e = e->next;
    }
}
