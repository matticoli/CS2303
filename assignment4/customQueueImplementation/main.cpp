//
// Created by Mikel Matticoli on 2/14/18.
//

#include <iostream>
#include <math.h>
#include "Event.h"
#include "CustomerEvent.h"
#include "SortedEventQueue.h"
#include "TellerEvent.h"

// Function prototypes for non-class functions
int randTime(double min, double max);
int runSim(int customerCount, int tellerCount, double simDuration, double avgSvcTime, bool sharedQueue);

/**
 * Parses command line arguments and runs simulation with and without shared queue
 * @param argc number of args
 * @param argv string array of args
 * @return program exit code (==0 for success, !=0 for error)
 */
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

    return runSim(customerCount, tellerCount, simDuration, avgSvcTime, true) +
           runSim(customerCount, tellerCount, simDuration, avgSvcTime, false);
}

/**
 * Run simulation with given parameters
 * @param customerCount number of customers
 * @param tellerCount number of tellers
 * @param simDuration simulation duration (minutes)
 * @param avgSvcTime average service time (minutes)
 * @param sharedQueue whether or not to use one shared TellerQueue across all tellers
 * @return 0 for success, 1 for error
 */
int runSim(int customerCount, int tellerCount, double simDuration, double avgSvcTime, bool sharedQueue) {
    std::cout << "\nRunning simulation with " << (sharedQueue ? "shared queue" : "individual queues") << std::endl;
    int simTime = 0; // Counter to track simulation time (minutes)

    double avgWaitTime = 0; // Counter to track wait time
    double customerWaitTimes[customerCount] = { }; // Array to track customer wait times for calculating statistics
    int customerIndex = 0; // Current index in wait times array


    SortedEventQueue *eventQueue = new SortedEventQueue();
    // If using a shared queue, init a shared queue
    TellerQueue *customerQueue;
    if(sharedQueue) customerQueue = new TellerQueue();

    // Create arrival events for customers and add them to the event queue
    for(int i = 0; i < customerCount; i++) {
        // Invariant: new CustomerEvent will be created and added to event queue
        CustomerEvent *c = new CustomerEvent(randTime(0, simDuration), CEventType::ARRIVE);
        eventQueue->add(c);
        // Invariant: CustomerEvent c has been created and added to eventQueue
    }

    // Create teller events at time 0 (bank open) and add them to the event queue
    for(int i = 0; i < tellerCount; i++) {
        // Invariant: new TellerEvent will be created and added to event queue
        // Init with shared queue or new unique queue
        TellerEvent *t = new TellerEvent(0, (sharedQueue ? customerQueue : new TellerQueue()) );
        eventQueue->add(t);
        // Invariant: TellerEvent c has been created and added to eventQueue
    }

    while(simTime < simDuration) {
        // Process events at head of queue that are timestamped at current time
        // Invariant: simTime will be incremented by 1
        while(eventQueue->peek()->startTime == simTime) {
            // Invariant: First event in eventQueue will be processed and retasked/deleted
            Event *e = eventQueue->pop();
            if(e->getType() == "Teller") {
                TellerEvent *t = static_cast<TellerEvent *>(e);
                // If there's a customer waiting
                if(t->queue->peek() != nullptr) {
                    // Serve the customer for a random amount of time
                    CustomerEvent *c = t->queue->pop();
                    int serveTime = randTime(1, avgSvcTime * 2);
                    c->retask(simTime + serveTime, CEventType::SERVED);
                    t->retask(simTime + serveTime);
                    eventQueue->add(t);
                    eventQueue->add(c);
                } else {
                    //No customers, idle for random amount of time
                    int idleTime = randTime(1, avgSvcTime * 2);
                    t->retask(simTime + idleTime);
                    eventQueue->add(t);
                }
            } else if (e->getType() == "Customer") {
                CustomerEvent *c = static_cast<CustomerEvent *>(e);
                switch(c->eventType) {
                    case CEventType ::ARRIVE:
                        // Customer arrived, put them in the shortest customer queue
                        // If using shared queue, shortestTellerQueue will always point to the same queue
                        c->retask(simTime, CEventType::WAIT);
                        TellerQueue::shortestTellerQueue->add(c);
                        break;
                    default:
                    case CEventType ::SERVED:
                        // Customer is done being served and can now leave. Save necessary data for stats and delete
                        customerWaitTimes[customerIndex] = simTime - c->arrivalTime;
                        customerIndex++;
                        avgWaitTime +=  simTime - c->arrivalTime;
                        delete c;
                        break;
                }
            } else {
                std::cerr << "Error, unrecognized event type" << std::endl;
                return 1;
            }
            // Invariant: First event in eventQueue has been processed and retasked/deleted
        }
        simTime++;
        // Invariant: simTime has been incremented by 1
    }

    // Calculate the average
    avgWaitTime /= customerCount;
    // Calculate the standard deviation:
    double stdDv = 0.0;
    // Calculate sum( (x-xbar)^2 )
    for(int i = 0; i < customerCount; i++) {
        // Invariant stdDv will be incremented by (x-xbar)^2 for x=ith element of customerWaitTimes
        double dx = (customerWaitTimes[i] - avgWaitTime);
        stdDv += dx*dx;
        // Invariant stdDv has been incremented by (x-xbar)^2 for x=ith element of customerWaitTimes

    }
    // Divide by x-1 and take root to get s
    stdDv /= customerCount - 1;
    stdDv = sqrt(stdDv);


    std::cout << "Average wait time with " << (sharedQueue ? "shared queue" : "individual queues") << " is "
              << round(avgWaitTime * 100) / 100 << " minutes" << std::endl;
    std::cout << "Standard deviation of wait times with "
              << (sharedQueue ? "shared queue" : "individual queues") << " is "
              << round(stdDv * 100) / 100 << " minutes" << std::endl;
    return 0;
}

/**
 * Generate random time in minutes between min and max time
 * @param min lower bound for rand time
 * @param max upper bound for rand time (exclusive)
 * @return random time between min and max
 */
int randTime(double min, double max) {
    return (int)(rand() * (max - min) / float(RAND_MAX) + min);
}