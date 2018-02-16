#include <iostream>
#include <cstdlib>
#include "Event.h"
#include "CustomerEvent.h"
#include "SortedEventQueue.h"
#include "TellerEvent.h"


int main(int argc, char *argv[]) {
    srand(time(NULL));
    // If missing args, print usage
    if(argc < 5) {
        std::cout << "Usage:" << std::endl
                  << "./qSim #customers #tellers simulationTime averageServiceTime <seed>" << std::endl;
        return 1;
    }

    // Parse command line args
    int customerCount = atoi(argv[1]);
    int tellerCount = atoi(argv[2]);
    double simDuration = atof(argv[3]);
    double avgSvcTime = atof(argv[4]);

    // If any args are invalid, print usage and >0 warning
    if(!customerCount || !tellerCount || !simDuration || !avgSvcTime) {
        std::cout << "Usage:" << std::endl
                  << "./qSim #customers #tellers simulationTime averageServiceTime <seed>" << std::endl
                  << "Note that all required parameters must be greater than 0" << std::endl;
        return 1;
    }

    double simTime = 0;

    Event *e = new Event(2.0, 2.0);
    std::cout << e->toString() << std::endl;


    SortedEventQueue *eventQueue = new SortedEventQueue();

    for(int i = 0; i < customerCount; i++) {
        Event *c = new CustomerEvent(rand() * simDuration / float(RAND_MAX), 0, CEventType::ARRIVE);
        eventQueue->add(c);
    }

    for(int i = 0; i < tellerCount; i++) {
        Event *t = new TellerEvent(0, 0, TEventType::IDLE);
        eventQueue->add(t);
    }

    while(simTime < simDuration) {
        while(eventQueue->peek()->startTime == simTime) {
            Event *e = eventQueue->pop();
            if(e->getType() == "Teller") {
                TellerEvent *t = static_cast<TellerEvent *>(e);
                // TODO check queue on completion of idle or serve event, create a new event
            } else if (e->getType() == "Customer") {
                CustomerEvent *c = static_cast<CustomerEvent *>(e);
                // TODO if arrival, put customer in queue, elif wait, put in evt queue, elif serve, destroy
            } else {
                std::cerr << "Error, unrecognized event type" << std::endl;
                return 1;
            }
        }
        simTime++;
    }

    return 0;
}