//
// Created by Mikel Matticoli on 2/14/18.
//

#ifndef ASSIGNMENT4_GRID_H
#define ASSIGNMENT4_GRID_H

#include <iostream>
#include <vector>
#include <queue>
using std::vector;

#include "Organism.h"


// Forward declaration of Organism since classes are mutually referential
class Organism;

/**
 * Utility class for storing x, y coordinates in grid (e.g. for returning an array or vector of coords)
 */
class Cell {
public:
    /**
     * Default constructor for Cell obj
     * @param x x position in grid
     * @param y y position in grid
     */
    Cell(int x, int y) : x(x), y(y){};
    int x;// x pos
    int y;// y pos
};

/**
 * Container class for bug grid, internally represented as a 2D array of Organism*
 */
class Grid {
private:
    /**
     * 2D Array of Organism pointers for storing bug grid
     */
     Organism ***grid;

    // Utility functions (not to be used outside of Grid)
    int randMax(int max);
    int randIndex();
public:
    /**
     * Grid size (width and height, grid is square)
     */
    int size;

    /**
     * Total number of organisms
     */
    int numOrganisms;
    /**
     * Total number of doodlebugs
     */
    int doodleCount;
    /**
     * Total number of ants
     */
    int antCount;

    Grid(int size);
    void print();
    bool add(Organism &o, int x, int y);
    void addRand(Organism &o);
    bool inBounds(int x, int y);
    bool occupied(int x, int y);
    void remove(int x, int y);
    void move(int fromx, int fromy, int x, int y);
    Organism *getAdjecentOrganism(int x, int y);
    Cell *getEmptyAdjecentCell(int x, int y);
    void moveAll();
};



#endif //ASSIGNMENT4_GRID_H
