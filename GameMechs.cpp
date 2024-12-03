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


//*big changes to generate food since it was giving me problesm
//*screen froze and stuff when about to collect food. I think food was just spawning on top of the body causing an infinite loop or smthn so I just completely re did it using some logic we had before too.

void GameMechs::generateFood(const objPosArrayList* playerList)
{



    const int maxCoords = (boardSizeX - 2) * (boardSizeY - 2);                 //*same thign getting max size ofstuff just no longer useing blockoff... instead making board boarsize-2 so its jus the playing field.
    objPos validPositions[maxCoords];                                           //*think ppa3. setting up an array with enough spaces for the entire gameplay area
    int takenCounter = 0;                                   //*marks whats taken and not

    //*iterates through board
    for (int x = 1; x < boardSizeX - 1; ++x) {
        for (int y = 1; y < boardSizeY - 1; ++y) {
            objPos placedFood(x, y, 'o');
            bool overlaps = false;

            //*checks for overlap with body.
            for (int i = 0; i < playerList->getSize(); ++i) {
                auto element = playerList->getElement(i);           //*Note I don't think we learned this in class but auto data-type lets C++ compiler check waht data type it is. I'm too alzy to find out what it rlly is so... (also named elelemtn cuz we getELement is called so ez to track)
                if (placedFood.isPosEqual(&element)) {
                    overlaps = true;
                    break;
                }
            }

           //*storing the free spaces in the array and incrementing onto the next index number.
            if (!overlaps) {
                validPositions[takenCounter++] = placedFood;  
            }
        }
    }

   //*we don't need this... but if someone fills up the entire board with the snake we just leacve the function. just an edge case I've seen in in previous snake games in hs
    if (takenCounter == 0) {
        return;
    }

 //*choosing a random spot from the tkane counter
    int index = rand() % takenCounter;
    foodPos = validPositions[index];  //*put food there
}


//*the gen food function literally makes sure we spawning on board, not overlapping, storing the validPositions, and then choosing one of those valid position to set the foodPos to. SIMEPL BUT KILELD ME
//*using blockoff was giving me errors and crashing so I chanegd it to accept the playerlist


//====================================================================================================================
//redid logic of food gen without block off cuz it was glitchy


    /*static bool seeded = false;
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
    */


//^leaving a comment if come here Mohammed
//^I had to change a few things most of the logic is what you wrote but we didnt need a const do a deep copy, I was crashing without it cuz that was a shallow copy.
//^also the random stuff wasen't working so I added a little check at the top of the generateFood Function.


//====================================================================================================================

objPos GameMechs::getFoodPos() const
{
    return foodPos;
}


void GameMechs::setGrowthFlag(){
    growthFlag = true;
}

bool GameMechs::getGrowthFlag()const{
    return growthFlag;
}