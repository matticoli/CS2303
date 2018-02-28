//
// Created by student on 2/26/18.
//

#include "Ant.h"

/**
 * Initializes ant to be placed in given grid
 * @param gridPtr grid that organism will be added to (NOT HANDLED BY CONSTRUCTOR)
 */
Ant::Ant(Grid *gridPtr) : Organism(gridPtr) {
    life = 0;
}

/**
 * Gets type of organism (to be overridden in subclass)
 * @return one of DOODLE, ANT, or ORGANISM (Organism::Type)
 */
Organism::Type Ant::getType() {
    return ANT;
}

/**
 * Moves ant to adjecent empty cell, or breeds where appropriate
 */
void Ant::move() {
    life++;
    Cell *c = grid->getEmptyAdjecentCell(x, y);
    if(!c) {
        return;
    }
    grid->move(x, y, c->x, c->y);

    if(life >=3) {
        breed();
    }
}

/**
 * Spawns a new ant in a adjecent empty cell if one is available
 */
void Ant::breed() {
    // Find a birthplace
    Cell *c = grid->getEmptyAdjecentCell(x, y);
    // If cell exists
    if(c) {
        // Add item to grid
        grid->add(*new Ant(grid), c->x, c->y);
        life = 0;
    }
}
