//
// Created by Mikel Matticoli on 2/27/18.
//

#include "Doodlebug.h"

/**
 * Initializes doodlebug to be placed in given grid
 * @param gridPtr grid that organism will be added to (NOT HANDLED BY CONSTRUCTOR)
 */
Doodlebug::Doodlebug(Grid *gridPtr) : Ant(gridPtr) {
    hunger = 0;
}

/**
 * Gets type of organism (to be overridden in subclass)
 * @return one of DOODLE, ANT, or ORGANISM (Organism::Type)
 */
Organism::Type Doodlebug::getType() {
    return DOODLE;
}

/**
 * Moves doodlebug to adjecent cell, eating an ant if one is around or picking
 * an empty adjecent cell and moves there. It will also die if/when appropriate.
 */
void Doodlebug::move() {
    Organism *o = grid->getAdjecentOrganism(x, y);
    if(o) {
        int newx = o->x, newy = o->y;
        grid->remove(newx, newy);
        grid->move(x, y, newx, newy);
        hunger = 0;
    } else {
        hunger++;
        Cell *c = grid->getEmptyAdjecentCell(x, y);
        if(c) {
            grid->move(x, y, c->x, c->y);
        }
    }

    life++;
    if(life >=8) {
        breed();
    }

    if(hunger >=3) {
        die();
    }
}

/**
 * Doodlebug removes itself fromg the grid
 */
void Doodlebug::die() {
    grid->remove(x, y);
}
