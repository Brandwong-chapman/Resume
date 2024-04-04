#include "World.h"

int main(int argc ,char **argv){
    // amount of levels, level size, starting lives, % of coins, % of nothing, % of Goombas, % of Koopas , % of mushrooms.
    //World *world = new World(3,2,2,10,10,60,10,10); stoi
    World *world = new World(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]),stoi(argv[4]),stoi(argv[5]),stoi(argv[6]),stoi(argv[7]),stoi(argv[8]));
    //cout << argv[1] << endl;
    //Level *level = new Level(2,10,60,10,10,10, false);
    //Hero *hero = new Hero(3);
    //Move *move = new Move(hero);
    //move->updateLevel(level);
    // level->printLevel();
    // level->placeHero();
    // level->printLevel();
    // move->moveRandomly();
    // level->printLevel();
    // hero->printHeroStatus();
    //delete level;
    //delete move;
    //world->printLevels();
    world->runWorld();

    delete world;
    return 1;
}