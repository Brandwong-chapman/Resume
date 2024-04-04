#include "Move.h"

Move::Move(){
}

Move::Move(Hero* hero){
    default_random_engine
    randomNumbreGenerator(random());
    objects = new Objects(hero);
}

Move::~Move(){
    delete objects;
}

string Move::moveRandomly(){
    amountOfMoves++;
    int randomMovement = determineDirection();
    switch (randomMovement)
    {
    case 1:
        return moveUp();
        break;
    case 2:
        return moveDown();
        break;
    case 3:
        return moveLeft();
        break;
    case 4:
        return moveRight();
        break;
    default:
        break;
    }
}

string Move::moveUp(){
    
    if(level->heroRow == 0){
        return objects->interact(level->getObjectAtPosition(level->mSize-1, level->heroCol), level->mSize-1, level->heroCol, "up");
    } else {
        return objects->interact(level->getObjectAtPosition(level->heroRow-1, level->heroCol), level->heroRow-1, level->heroCol, "up");
    }
}

string Move::moveDown(){
    if(level->heroRow == level->mSize-1){
        return objects->interact(level->getObjectAtPosition(0, level->heroCol), 0, level->heroCol, "down");
    } else {
        return objects->interact(level->getObjectAtPosition(level->heroRow+1, level->heroCol), level->heroRow+1, level->heroCol, "down");
    }
}

string Move::moveLeft(){
    if(level->heroCol == 0){
        return objects->interact(level->getObjectAtPosition(level->heroRow, level->mSize-1), level->heroRow, level->mSize-1, "left");
    } else {
        return objects->interact(level->getObjectAtPosition(level->heroRow, level->heroCol-1), level->heroRow, level->heroCol-1, "left");
    }
}

string Move::moveRight(){
    if(level->heroCol == level->mSize-1){
        return objects->interact(level->getObjectAtPosition(level->heroRow, 0), level->heroRow, 0, "right");
    } else {
        return objects->interact(level->getObjectAtPosition(level->heroRow, level->heroCol+1), level->heroRow, level->heroCol+1, "right");
    }
}

unsigned int Move::determineDirection(){
    uniform_int_distribution<int> distribution(1, 4);
    return distribution(random);
}

void Move::updateLevel(Level* nextLevel){
    level = nextLevel;
    objects->updateLevel(level);
}