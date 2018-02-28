//
// Created by Mikel Matticoli on 2/26/18.
//

#ifndef ASSIGNMENT4_ANT_H
#define ASSIGNMENT4_ANT_H


#include "Organism.h"

class Ant : public Organism {
    protected:
        /**
         * timesteps of life since last breed
         */
        int life = 0;

    public:
        Ant(Grid *gridPtr);
        virtual Organism::Type getType() override;
        virtual void move() override;
        virtual void breed();
};


#endif //ASSIGNMENT4_ANT_H
