//
// Created by Mikel Matticoli on 2/14/18.
//

#include <iostream>
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"

///PA5 gridSize #doodlebugs #ants #time_steps seed pause

/**
 * Parses command line arguments and runs simulation
 * @param argc number of args
 * @param argv string array of args
 * @return program exit code (==0 for success, !=0 for error)
 */
int main(int argc, char *argv[]) {
    // If missing args, print usage
    if(argc <= 1) {
        std::cout << "Usage:" << std::endl
                  << "./PA5 gridSize #doodlebugs #ants #time_steps seed pause" << std::endl << std::endl
                  << "Using default parameters..." << std::endl;
    }

    // Parse command line args
    int gridSize = (argc >= 2 ? atoi(argv[1]) : 20); // Side length of grid
    int numDoodle = (argc >= 3 ? atoi(argv[2]) : 5); // Number of Doodlebugs at start
    double numAnt = (argc >= 4 ? atoi(argv[3]) : 100); // Number of ants at start
    double timeSteps = (argc >= 5 ? atoi(argv[4]) : 1000); // Max number of time steps
    bool pause = false; // Whether or not to pause and print after each round
    // If seed arg
    if(argc >= 6) {
        // Call srand with arg
        int seed = atoi(argv[5]);
        srand(seed);
    } else {
        // Else seed random with system time
        srand(time(NULL));
    }
    // If pause arg
    if(argc >= 7) {
        // Set
        pause = atoi(argv[6]);
    }
    // Make sure the prgrm did not receive invalid args
    // (gridsize 0 will cause segfault, and 0 timesteps will just terminate)
    if(!gridSize || !timeSteps) {
        std::cout << "Usage:" << std::endl
                  << "./PA5 gridSize #doodlebugs #ants #time_steps seed pause" << std::endl << std::endl;
        return EXIT_FAILURE;
    }

    // Print initial sim info
    std::cout << "Running " << timeSteps << " steps with grid of size " << gridSize << ", " << numDoodle
              << " doodlebugs and " << numAnt << " ants." << (pause ? " Will pause." : "") << std::endl;

    // Make the grid
    Grid *grid = new Grid(gridSize);
    // Spawn dem doodles
    for(int i = 0; i < numDoodle; i++) {
        Doodlebug *d = new Doodlebug(grid);
        grid->addRand(*d);
    }
    // Spawn dem ants
    for(int i = 0; i < numAnt; i++) {
        Ant *a = new Ant(grid);
        grid->addRand(*a);
    }
    // Print initial population
    std::cout << "Initial Doodle Population: " << grid->doodleCount << "\tAnts: " << grid->antCount << std::endl;

    // Print out the initial grid
    grid->print();

    // Run the simulation
    for(int i= 1; i < timeSteps && grid->doodleCount > 0 && grid->antCount > 0; i++) {
        // Process move step for all bugs
        grid->moveAll();
        // If pause param evals to true
        if(pause) {
            // print the grid for this timestep and wait
            grid->print();
            getchar();
        }
    }
    // Print final grid and stats
    std::cout << "Final Grid:" << std::endl;
    grid->print();
    std::cout << "Final Doodle Population: " << grid->doodleCount << "\tAnts: " << grid->antCount << std::endl;

    return EXIT_SUCCESS;
}
