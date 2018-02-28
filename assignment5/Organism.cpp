//
// Created by Mikel Matticoli on 2/26/18.
//

#include "Organism.h"

/**
 * Initializes organism to be placed in given grid
 * @param gridPtr grid that organism will be added to (NOT HANDLED BY CONSTRUCTOR)
 */
Organism::Organism(Grid *gridPtr) : grid(gridPtr) {
}

/**
 * Gets type of organism (to be overridden in subclass)
 * @return one of DOODLE, ANT, or ORGANISM (Organism::Type)
 */
Organism::Type Organism::getType() {
    return ORGANISM;
}

/**
 * String representation of organism
 * @return "x" for doodlebug, "o" for ant, "?" for unrecognized derived class
 */
std::string Organism::toString() {
    return getType() == DOODLE ? (std::string)"x" : getType() == ANT ? (std::string)"o" : (std::string)"?";
}
