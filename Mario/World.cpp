#include "World.h"

World::World(int levelAmount, int size, int startingLives, int coinChance, int nothingChance, int goombaChance, int koopaChance, int mushroomChance){
    if (levelAmount < 0|| size < 0 || startingLives < 0)
        throw runtime_error("inputs need to be non negative");
    if (levelAmount == 0)
        throw runtime_error("there needs to be 1 or more levels");
    amountOfLevels = levelAmount;
    file = new FileProcessor("log.txt");
    hero = new Hero(startingLives, file);
    move = new Move(hero);
    generateLevels(size, coinChance, nothingChance, goombaChance, koopaChance, mushroomChance);
}

World::~World(){
    delete levels[currentLevel];
    delete[] levels;
    delete move;
}

void World::runWorld(){
    printLevels();
    while(!hasHeroWon() && !hasHeroLost()){
        runLevel();
        if (hasHeroWon() || hasHeroLost())
            break;
        file->writeLine("~~~~~~~~~~~~~~~~~~");
        nextLevel();
    }
    if (hasHeroWon()){
        file->writeLine( "It took Mario " + to_string(move->amountOfMoves) + " moves to save the princess with " +
         to_string(hero->coinAmount) + " coins at a power level of " + to_string(hero->powerLevel) + " and " + to_string(hero->lives) + " lives left.");
    } else if (hasHeroLost()){
        file->writeLine( "Mario has run out of lives");
        file->writeLine( "Mario had moved " + to_string(move->amountOfMoves) + " times before he was defeated.");
        file->writeLine( "       GAME OVER");
    } else {
        file->writeLine( "Check your code again");
    }
    file->enter();
}

void World::runLevel(){
    file->enter();
    string output;
    file->writeLine( "     LEVEL " + to_string(currentLevel+1));
    file->writeLine( "__________________");
    file->enter();
    levels[currentLevel]->placeHero();
    levels[currentLevel]->printLevel();
    file->writeLine( "Mario is starting at (" + to_string(levels[currentLevel]->heroRow) + "," + to_string(levels[currentLevel]->heroCol) + ").");
    file->writeLine( "__________________");
    file->enter();
    while(!levels[currentLevel]->isLevelCleared){
        output = move->moveRandomly();
        levels[currentLevel]->printLevel();
        file->writeLine( "Mario " + output);
        file->writeLine( "Level: " + to_string(currentLevel+1) + ". Mario is now at position: (" + to_string(levels[currentLevel]->heroRow) + "," + to_string(levels[currentLevel]->heroCol) + ")");
        if(hasHeroWon() || hasHeroLost()){
            break;
        }
        hero->printHeroStatus();
        file->enter();
    }
}

void World::generateLevels(int size, int coinChance, int nothingChance, int goombaChance, int koopaChance, int mushroomChance){
    levels = new Level*[amountOfLevels];
    //generates all exept for the final level
    for (int i = 0; i < amountOfLevels-1; ++i ){
        levels[i] =  new Level(size, coinChance, nothingChance, goombaChance, koopaChance, mushroomChance, false, file);
    }
    levels[amountOfLevels-1] = new Level(size, coinChance, nothingChance, goombaChance, koopaChance, mushroomChance, true, file);
    currentLevel = 0;
    move->updateLevel(levels[currentLevel]);
}

void World::nextLevel(){
    if (currentLevel != 0)
        delete levels[currentLevel-1];
    if (currentLevel != amountOfLevels-1)
        move->updateLevel(levels[++currentLevel]);
}

bool World::hasHeroWon(){
    return (levels[currentLevel]->isBossDefeated && levels[currentLevel]->isFinalLevel);
}

bool World::hasHeroLost(){
    return hero->isHeroDefeated;
}

void World::printLevels(){
    file->writeLine( "     LEVELS");
    for (int i = 0; i < amountOfLevels;++i){
        file->writeLine( "================");
        levels[i]->printLevel();
    }
    file->writeLine( "================");
    file->enter();
}
