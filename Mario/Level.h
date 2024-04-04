#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <random>
#include <exception>
#include "FileProcessor.h"
using namespace std;


class Level{
    public:
        Level();
        Level(int size, int coinChance, int nothingChance, int goombaChance, int koopaChance, int mushroomChance, bool finalLevel, FileProcessor* writeFile);
        ~Level();
        void printLevel();
        char placeObject();
        // Objects that there can only be one of in each level
        void placeSpecialObjects();
        char** level;
        bool isLevelCleared;
        void moveHero(unsigned int xPosition, unsigned int yPosition);
        void placeHero();
        void respawnHero();
        char getObjectAtPosition(unsigned int xPosition, unsigned int yPosition);
        bool isBossDefeated;
        unsigned int heroRow;
        unsigned int heroCol;
        unsigned int mSize;
        bool isFinalLevel;


    private:
        FileProcessor* file;
        random_device random;
        unsigned int spawnRow;
        unsigned int spawnCol;
        unsigned int mCoinChance;
        unsigned int mNothingChance;
        unsigned int mGoombaChance;
        unsigned int mKoopaChance;
        unsigned int mMushroomChance;     
};


#endif
