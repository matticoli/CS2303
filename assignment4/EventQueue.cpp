//
// Created by student on 2/14/18.
//

#include "EventQueue.h"

void EventQueue::add(Event &e) {
    // If no root
    if(!this->root) {
        // Set Event as root
        this->root = &e;
    }
    // else, find tail
    Event *tail = root;
    while(tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = &e;
}

Event * EventQueue::peek() {
    return root;
}

Event * EventQueue::pop() {
    Event *n = root;
    root = root->next;
    return n;
}