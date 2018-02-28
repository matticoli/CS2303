//
// Created by Mikel Matticoli on 2/27/18.
//

#ifndef ASSIGNMENT4_DOODLEBUG_H
#define ASSIGNMENT4_DOODLEBUG_H


#include "Ant.h"

class Doodlebug : public Ant {
public:
    int hunger;
    Doodlebug(Grid *gridPtr);

    Type getType();

    void move() override;

    void die();
};


#endif //ASSIGNMENT4_DOODLEBUG_H
