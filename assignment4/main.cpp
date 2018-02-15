#include <iostream>
#include "Event.h"

int main() {
    double simDuration = 100;

    std::cout << "Hello, World!" << std::endl;
    Event *e = new Event(2.0, 2.0);
    std::cout << e->toString() << std::endl;

    double simTime = 0;
    while(simTime < simDuration) {
        simTime++;
    }

    return 0;
}