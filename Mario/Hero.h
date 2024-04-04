#ifndef HERO_H
#define HERO_H

#include "Level.h"

class Hero{
    public:
        Hero();
        Hero(unsigned int startingLives, FileProcessor* writeFile);
        ~Hero();
        string collectCoin();
        void collectMushroom();
        string takeDamage(int damage);
        void updateLevel(Level* nextLevel);
        void printHeroStatus();
        string defeatEnemy();
        int lives;
        int powerLevel;
        bool isHeroDefeated;
        unsigned int coinAmount;
        int enemiesDefeated;
        Level* level;
        FileProcessor* file;
};

#endif
