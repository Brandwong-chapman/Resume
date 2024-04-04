#ifndef MOVE_H
#define MOVE_H

#include "Objects.h"
#include "Hero.h"
#include "Level.h"

class Move{
    public:
        Move();
        Move(Hero* hero);
        ~Move();
        string moveRandomly();
        string moveUp();
        string moveDown();
        string moveLeft();
        string moveRight();
        unsigned int determineDirection();
        void updateLevel(Level* nextLevel);
        random_device random;
        Level* level;
        Objects* objects;
        int amountOfMoves;
};

#endif
