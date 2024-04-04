#include "Level.h"

Level::Level(int size, int coinChance, int nothingChance, int goombaChance, int koopaChance, int mushroomChance, bool finalLevel, FileProcessor* writeFile){
    file = writeFile;
    isLevelCleared = false;
    isBossDefeated = false;
    mCoinChance = coinChance;
    mNothingChance = nothingChance;
    mGoombaChance = goombaChance;
    mKoopaChance = koopaChance;
    isFinalLevel = finalLevel;
    mMushroomChance = mushroomChance;
    if (mCoinChance + mNothingChance + mGoombaChance + mKoopaChance + mMushroomChance != 100){
        throw runtime_error("Sum of the objects spawn chance is not equal to then 100");
    }
    if (size <= 1){
        throw runtime_error("The size of levels must be 2 or higher");
    }
    default_random_engine
    randomNumbreGenerator(random());
    mSize = size;
    level = new char*[mSize];
    // making 2D array
    for (int row = 0; row < mSize; ++row){
        level[row] = new char[mSize];
        for (int col = 0; col < mSize; ++col){
            level[row][col] = placeObject();
        }    
    }
    placeSpecialObjects();
}

Level::~Level(){
    for (int row = 0; row < mSize; ++row){
        delete[] level[row];
    }
    delete[] level;
}

void Level::printLevel(){
    for (int row = 0; row < mSize; ++row){
        file->write(" ");
        for (int col = 0; col < mSize; ++col){
            string object(1,level[row][col]);
            file->write(" " + object + " ");
        }
        file->enter();
    }
}

char Level::placeObject(){
    uniform_int_distribution<int> distribution(1, 100);
    int randomNumber = distribution(random);
    if (randomNumber < mCoinChance){
        return 'c';
    } else if (randomNumber < mCoinChance + mNothingChance){
        return 'x';
    } else if (randomNumber < mCoinChance + mNothingChance + mGoombaChance){
        return 'g';
    }else if (randomNumber < mCoinChance + mNothingChance + mGoombaChance + mKoopaChance){
        return 'k';
    } else {
        return 'm';
    }
}

void Level::placeSpecialObjects(){
    uniform_int_distribution<int> distribution(0, (mSize*mSize)-1);
    bool isHeroPlaced = false;
    bool isBossPlaced = false;
    bool isPipePlaced = false;
    int placedPositions[] = {-1,-1,-1};
    int placedObjects = 0;
    while (placedObjects != 3){
        int randomNumber = distribution(random);
        if (randomNumber != placedPositions[0] && randomNumber != placedPositions[1] && randomNumber != placedPositions[2]){
            if(!isHeroPlaced){
                //randomNumber-(randomNumber%mSize))/mSize should = row and randomNumber%mSize should = col
                heroRow = (randomNumber-(randomNumber%mSize))/mSize;
                heroCol = randomNumber%mSize;
                spawnRow = heroRow;
                spawnCol = heroCol;
                level[heroRow][heroCol] = 'x';
                placedPositions[0] = randomNumber;
                placedObjects++;
                isHeroPlaced = true;
            } else if (!isBossPlaced){
                level[(randomNumber-(randomNumber%mSize))/mSize][randomNumber%mSize] = 'b';
                placedPositions[1] = randomNumber;
                placedObjects++;
                isBossPlaced = true;
                if (isFinalLevel){
                    break;
                }
            } else if (!isPipePlaced){
                level[(randomNumber-(randomNumber%mSize))/mSize][randomNumber%mSize] = 'w';
                placedPositions[2] = randomNumber;
                placedObjects++;
                isPipePlaced = true;
            }
        }
    }
}

void Level::moveHero(unsigned int rowPosition, unsigned int colPosition){
    level[heroRow][heroCol] = 'x';
    level[rowPosition][colPosition] = 'H';
    heroRow = rowPosition;
    heroCol = colPosition;
}

void Level::placeHero(){
    level[heroRow][heroCol] = 'H';
}

void Level::respawnHero(){
    moveHero(spawnRow, spawnCol);
}

char Level::getObjectAtPosition(unsigned int xPosition, unsigned int yPosition){
    return level[xPosition][yPosition];
}