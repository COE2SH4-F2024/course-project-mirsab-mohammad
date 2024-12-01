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
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    foodPos.setObjPos(-1,-1,'o');
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
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

void GameMechs::generateFood(objPos blockOff)
{

     int x = 0;
     int y = 0;
     bool var = true;


    objPosArrayList* playerPosList= new objPosArrayList();

    while(var) {
        x = rand() % (getBoardSizeX() - 2) + 1;
        y = rand() % (getBoardSizeY() - 2) + 1;

        foodPos.x = x;
        foodPos.y = y;

        if (foodPos.x== (boardSizeX - 1 ) || foodPos.y == (boardSizeY - 1)) {
            continue;
        }

        for (int i; i < playerPosList -> getSize(); i++) {
            objPos tempPos;
            playerPosList -> getElement(tempPos, i);
            if (foodPos.y == tempPos.y && foodPos.x == tempPos.x) {
                continue;
            }
        }

        break;
    }
    delete playerPosList;
}

objPos GameMechs::getFoodPos() const
{
    return foodPos;
}