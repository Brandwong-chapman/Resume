#ifndef OBJECTS_H
#define OBJECTS_H

#include "Level.h"
#include "Hero.h"

class Objects{
    public:
        Objects(Hero* vHero);
        ~Objects();
        string interact(char object, unsigned int objectsXPosition, unsigned int objectsYPosition, string move);
        //void enemyInteraction(unsigned int objectsXPosition, unsigned int objectsYPosition, bool hasWon, unsigned int damage);
        bool goombaInteraction();
        bool koopaInteraction();
        bool bossInteraction();
        bool fightEnemy(unsigned int defeatChance);
        void updateLevel(Level* nextLevel);

        Level* level;
        Hero* hero;

        
};


#endif