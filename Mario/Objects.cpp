#include "Objects.h"

Objects::Objects(Hero* vHero){   
    hero = vHero;
}

Objects::~Objects(){   
    delete hero;
}

string Objects::interact(char object, unsigned int objectsRow, unsigned int objectsCol, string move){
    switch (object)
    {
    case ('x'):
        level->moveHero(objectsRow,objectsCol);
        return "moved " + move + ".";
        break;
    case ('m'):
        hero->collectMushroom();
        level->moveHero(objectsRow,objectsCol);
        return "moved " + move + " and ate a mushroom.";
        break;
    case ('c'):
        level->moveHero(objectsRow,objectsCol);
        return "moved " + move + " and collected a coin" + hero->collectCoin();;
        break;
    case ('g'):
        if(goombaInteraction()){
            level->moveHero(objectsRow,objectsCol);
            return "stomped a Goomba and moved " + move + hero->defeatEnemy();
        } else {
            return "tried to move " + move + " somehow lost to a Goomba and " + hero->takeDamage(1);
        }
        break;    
    case ('k'):
        if(koopaInteraction()){
            level->moveHero(objectsRow,objectsCol);
            return "shelled a Koopa and moved " + move + hero->defeatEnemy();
        } else {
            return "tried to move " + move + " and was hurt by a Koopa and " + hero->takeDamage(1);
        }
        break;    
    case ('b'):
        if(bossInteraction()){
            level->moveHero(objectsRow,objectsCol);
            level->isBossDefeated = true;
            if (level->isFinalLevel){
                return "has moved " + move + " defeating Bowser and saving the princess";
            }
            level->isLevelCleared = true;
            return "has moved " + move + " defeating Bowser warping to the next level.";
        } else {
            return "tried to move " + move + " was bested by Bowser and " + hero->takeDamage(2);
        }
        break;  
    case ('w'):
        
        level->moveHero(objectsRow,objectsCol);
        level->isLevelCleared = true;
        return "has moved " + move + " warping to the next level.";
        break;  
    
    
    default:
        break;
    }
}

// void Objects::enemyInteraction(unsigned int objectsXPosition, unsigned int objectsYPosition, bool hasWon, unsigned int damage){
//     if (hasWon){
//         level->moveHero(objectsXPosition, objectsYPosition);
//     } else {
//         hero->takeDamage(damage);
//     }
// }

bool Objects::goombaInteraction(){
    return fightEnemy(80);
}

bool Objects::koopaInteraction(){
    return fightEnemy(65);
}

bool Objects::bossInteraction(){
    return fightEnemy(50);
}

bool Objects::fightEnemy(unsigned int defeatChance){
    random_device random;
    default_random_engine
    randomNumbreGenerator(random());
    uniform_int_distribution<int> distribution(1, 100);
    return (distribution(random) < defeatChance);
}

void Objects::updateLevel(Level* nextLevel){
    hero->updateLevel(nextLevel);
    level = nextLevel;
}

