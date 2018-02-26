//
// Created by Mikel Matticoli on 2/14/18.
//

#include "EventQueue.h"

EventQueue::EventQueue() {
    queue = new std::queue<Event *>();
}

/**
 * Adds event to queue
 * @param e Pointer to event to add to queue
 */
void EventQueue::add(Event *e) {
    queue->push(e);
}

/**
 * Returns head node of queue without removing it
 * @return first event in queue
 */
Event * EventQueue::peek() {
    return queue->front();
}

/**
 * Removes head node from queue and returns it
 * @return fist event in queue
 */
Event * EventQueue::pop() {
    Event *e = EventQueue::peek();
    queue->pop();
    return e;
}

/**
 * Calculates length of queue
 * @return number of events in queue
 */
int EventQueue::length() {
    return (int)queue->size();
}

/**
 * Prints string representation of queue to std::cout
 */
void EventQueue::print() {
    std::cout << "Event Queue" << std::endl;
    std::cout << queue << std::endl;
}
