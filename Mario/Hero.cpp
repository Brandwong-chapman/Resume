#include "Hero.h"

Hero::Hero(){
    lives = 3;
}

Hero::Hero(unsigned int startingLives, FileProcessor* writeFile){
    file = writeFile;
    lives = startingLives;
}


Hero::~Hero(){
}

string Hero::collectCoin(){
    coinAmount++;
    if (coinAmount == 20){
        lives++;
        coinAmount = 0;
        return " gaining a life.";
    }
    return ".";
}

void Hero::collectMushroom(){
    if (powerLevel != 2){
        powerLevel++;
    }
}

string Hero::takeDamage(int damage){
    powerLevel -= damage;
    if (powerLevel < damage){
        lives--;
        if (lives == -1){
            isHeroDefeated = true;
            
        } else {
            //level->respawnHero();
            powerLevel = 0;
            enemiesDefeated = 0;
        }  
         return "lost a life.";
    } else {
        if (damage == 1)
            return "lost a power level.";
        else 
            return "lost two power levels.";
    }
    
}

void Hero::updateLevel(Level* nextLevel){
    level = nextLevel;
}

void Hero::printHeroStatus(){
    file->writeLine( "Mario has " + to_string(coinAmount) + " coins, " + to_string(lives) + " lives, and is at power level " + to_string(powerLevel));
}

string Hero::defeatEnemy(){
    if (++enemiesDefeated == 7){
        lives++;
        enemiesDefeated = 0;
        return " and gained a life.";
    }
    return ".";
}
