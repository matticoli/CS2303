//
// Created by Mikel Matticoli on 2/26/18.
//

#ifndef ASSIGNMENT4_ORGANISM_H
#define ASSIGNMENT4_ORGANISM_H

#include <iostream>
#include "Grid.h"

// Forward declaration (classes are mutually referential)
class Grid;
class Cell;

class Organism {
public:
    /**
     * Enum for organism type (return value for getType())
     */
    enum Type {DOODLE, ANT, ORGANISM};
    /**
     * Pointer to grid that bug is contained in
     */
    Grid *grid;
    /**
     * Position of organism within grid
     */
    int x, y;

    Organism(Grid *gridPtr);
    virtual Organism::Type getType();
    std::string toString();
    /**
     * Abstract method - move procedure for Organism subclass
     */
    virtual void move() = 0;
};


#endif //ASSIGNMENT4_ORGANISM_H
