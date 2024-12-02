#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeY = 15;
    boardSizeX = 30;
    foodPos.setObjPos(-1,-1,'o');
    playerPosList = new objPosArrayList();
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    foodPos.setObjPos(-1, -1, 'o');
    playerPosList = new objPosArrayList();
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    delete playerPosList;
    playerPosList = nullptr;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() 

{
    if(MacUILib_hasChar()) {
        input = MacUILib_getChar();

    // # to exit
    } else if(input == 35){  
        setExitTrue();
    } 
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

void GameMechs::generateFood(const objPos blockOff)
{

    static bool seeded = false;
    if (!seeded){
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    //^ took this from a previous project I've done in the past, little extra tbh, just makes it so the random function isn't run all the time and the time functin returns a time in seconds. lemme know if you need me to explain it to ya

     int x = 0;
     int y = 0;
     bool checker = false;


    while(!checker) {
        x = rand() % (getBoardSizeX() - 2) + 1;
        y = rand() % (getBoardSizeY() - 2) + 1;

        if (foodPos.pos->x == blockOff.pos->x && foodPos.pos->y == blockOff.pos->y) {
            continue;
        }

        checker = true;
        for (int i = 0; i < playerPosList->getSize(); i++) {
            objPos tempPos = playerPosList->getElement(i);
            if (tempPos.pos->x == x && tempPos.pos->y == y){
                checker = false;
                break;
            }
        }

    }
    foodPos.setObjPos(x,y,'o');
}


//^leaving a comment if come here Mohammed
//^I had to change a few things most of the logic is what you wrote but we didnt need a const do a deep copy, I was crashing without it cuz that was a shallow copy.
//^also the random stuff wasen't working so I added a little check at the top of the generateFood Function.

objPos GameMechs::getFoodPos() const
{
    return foodPos;
}


void GameMechs::setGrowthFlag(){
    growthFlag = true;
}

void GameMechs::getGrowthFlag()const{
    return growthFlag;
}