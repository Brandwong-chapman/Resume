#ifndef WORLD_H
#define WORLD_H

#include "Move.h"
#include "Hero.h"
#include "Level.h"
#include "FileProcessor.h"

class World{
    public:
        World(int levelAmount, int size, int startingLives, int coinChance, int nothingChance, int goombaChance, int koopaChance, int mushroomChance);
        ~World();
        void generateLevels(int size, int coinChance, int nothingChance, int goombaChance, int koopaChance, int mushroomChance);
        void runWorld();
        void runLevel();
        void nextLevel();
        void printLevels();
        bool hasHeroWon();
        bool hasHeroLost();
        void playWinScreen();
        void playLoseScreen();
        int currentLevel;
        FileProcessor* file;
        Level** levels;
        Hero* hero;
        Move* move;
        int amountOfLevels;

};

#endif