//
// Created by Mikel Matticoli on 2/14/18.
//

#include "SortedEventQueue.h"

SortedEventQueue::SortedEventQueue() {
    queue = new std::priority_queue<Event *>();
}

/**
 * Adds event to queue
 * @param e Pointer to event to add to queue
 */
void SortedEventQueue::add(Event *e) {
    queue->push(e);
}

/**
 * Returns head node of queue without removing it
 * @return first event in queue
 */
Event * SortedEventQueue::peek() {
    return queue->top();
}

/**
 * Removes head node from queue and returns it
 * @return fist event in queue
 */
Event * SortedEventQueue::pop() {
    Event *e = SortedEventQueue::peek();
    queue->pop();
    return e;
}

/**
 * Calculates length of queue
 * @return number of events in queue
 */
int SortedEventQueue::length() {
    return (int)queue->size();
}

/**
 * Prints string representation of queue to std::cout
 */
void SortedEventQueue::print() {
    std::cout << "Sorted Queue" << std::endl;
    std::cout << queue << std::endl;
}
