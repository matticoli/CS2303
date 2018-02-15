#include <iostream>
#include "Event.h"

int main(int argc, char *argv[]) {
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

    while(simTime < simDuration) {
        simTime++;
    }

    return 0;
}