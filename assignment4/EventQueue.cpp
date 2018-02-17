//
// Created by student on 2/14/18.
//

#include "EventQueue.h"

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

Event * EventQueue::peek() {
    return root;
}

Event * EventQueue::pop() {
    Event *n = root;
    root = root->next;
    n->next = nullptr;
    return n;
}

int EventQueue::length() {
    int count = 0;
    for(Event *n = root; n->next != nullptr; n++) count++;
    return count;
}


void EventQueue::print() {
    std::cout << "Event Queue" << std::endl;
    Event *e = root;
    while(e) {
        std::cout << "\t" << e->toString() << std::endl;
        e = e->next;
    }
}
