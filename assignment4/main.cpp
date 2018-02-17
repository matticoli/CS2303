#include <iostream>
#include <cstdlib>
#include "Event.h"
#include "CustomerEvent.h"
#include "SortedEventQueue.h"
#include "TellerEvent.h"
#include "CustomerQueue.h"

int randTime(double min, double max) {
    return (int)(rand() * (max - min) / float(RAND_MAX) + min);
}

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

    double avgWaitTime = 0;

    SortedEventQueue *eventQueue = new SortedEventQueue();
    CustomerQueue *customerQueue = new CustomerQueue();

    for(int i = 0; i < customerCount; i++) {
        CustomerEvent *c = new CustomerEvent(randTime(0, simDuration), 0, CEventType::ARRIVE);
        eventQueue->add(c);
//        std::cout << "Added customer " << c->toString() << std::endl;
    }

    for(int i = 0; i < tellerCount; i++) {
        TellerEvent *t = new TellerEvent(0, 0, TEventType::IDLE, customerQueue);
        eventQueue->add(t);
//        std::cout << "Added Teller " << t->toString() << std::endl;

    }

    eventQueue->print();

    while(simTime < simDuration) {
//        std::cout << simTime << std::endl;

        while(eventQueue->peek()->startTime == simTime) {
            Event *e = eventQueue->pop();
            if(e->getType() == "Teller") {
                TellerEvent *t = static_cast<TellerEvent *>(e);
                if(t->queue->peek() != nullptr) {
//                    t->queue->print();
                    CustomerEvent *c = t->queue->pop();
                    int serveTime = randTime(1, avgSvcTime * 2);
//                    std::cout << t->toString() << " serving " << c->toString() << " until " << (simTime + serveTime) << std::endl;
                    t->retask(simTime + serveTime, 0, TEventType::SERVE);
                    c->retask(simTime + serveTime, 0, CEventType::SERVED);
                    eventQueue->add(t);
                    eventQueue->add(c);
                } else {
                    int idleTime = randTime(1, avgSvcTime * 2);
//                    std::cout << t->toString() << " idling until " << (simTime + idleTime) << std::endl;
                    t->retask(simTime + idleTime, 0, TEventType::IDLE);
                    eventQueue->add(t);
                }
            } else if (e->getType() == "Customer") {
                CustomerEvent *c = static_cast<CustomerEvent *>(e);
                switch(c->eventType) {
                    case CEventType ::ARRIVE:
//                        std::cout << "Customer arrived at " << simTime;
                        c->retask(simTime, 0, CEventType::WAIT);
                        CustomerQueue::shortestCustomerQueue->add(c);
                        break;
                    default:
                    case CEventType ::SERVED:
                        std::cout << "Customer left after " << simTime - c->arrivalTime << " minutes" << std::endl;
                        avgWaitTime +=  simTime - c->arrivalTime;
                        delete c;
                        break;
                }
            } else {
                std::cerr << "Error, unrecognized event type" << std::endl;
                return 1;
            }
        }
//        eventQueue->print();
//        std::cout << "Customer ";
//        CustomerQueue::shortestCustomerQueue->print();
        simTime++;
    }
    avgWaitTime /= customerCount;

    std::cout << std::endl << "Average wait time for shared queue is " << avgWaitTime << " minutes" << std::endl;

    return 0;
}