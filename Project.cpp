#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"



using namespace std;

#define DELAY_CONST 100000


//^ MIGHT NEED TO GET RID OF THIS IDK IF WE CAN HAVE GLOBAL VAR's BUT ITS THE ONLY WAY I CAN THINK OF IT WORKING

GameMechs* gameMechs = nullptr;
Player* player = nullptr;



bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(!gameMechs->getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{   
    srand(static_cast<unsigned int>(time(nullptr)));



    //^pray this works ima kms if it don't
    MacUILib_init();
    MacUILib_clearScreen();

    gameMechs = new GameMechs(30,15); 
    player = new Player(gameMechs);

    gameMechs->generateFood(player->getPlayerPos());




}

void GetInput(void)
{
    if (MacUILib_hasChar()){
    char input = MacUILib_getChar();

    if (input == '\n' || input == '\r'){
        gameMechs->setExitTrue();
    }

    else if (input == 'f'){
        gameMechs->generateFood(player->getPlayerPos()); //^debug check. click f to respawn the food
    }


    else{
        gameMechs->setInput(input);
    }
   }
}

void RunLogic(void)
{
    
    player -> updatePlayerDir();            //*same

    player-> movePlayer();                  //*same

    if (player->checkCollisionFood(gameMechs->getFoodPos())){           //*if we collide with food
        gameMechs->incrementScore();                                    //*score up
        player->grow();                                                 //*snake gorw
        gameMechs->generateFood(player->getPlayerPos());                //*more food spawn

    }
    if(gameMechs->getLoseFlagStatus()){                                 //*if the lsoe flag status tru
        gameMechs->setExitTrue();                                       //*leave
    }

    /*objPos head = player->getPlayerPos()->getHeadElement();
    objPos food = gameMechs->getFoodPos();
    if (head.isPosEqual(&food)){
        gameMechs -> incrementScore();
        gameMechs ->setGrowthFlag();
        gameMechs->generateFood(head);
    }

    if (gameMechs->getLoseFlagStatus()){
        gameMechs->setExitTrue();
    }

    char input = gameMechs->getInput();
    if (input != 0){
        gameMechs->clearInput();
    }
*/



}

void DrawScreen(void) {

    MacUILib_clearScreen();

    int sizeX = gameMechs->getBoardSizeX();
    int sizeY = gameMechs->getBoardSizeY();

    for (int row = 0; row < sizeY; row++) {

        for (int column = 0; column < sizeX; column++) {

            if (row == 0 || column == 0 || row == sizeY - 1 || column == sizeX - 1) {           //*make borders
                MacUILib_printf("#");

            } else if (row == gameMechs->getFoodPos().pos->y && column == gameMechs->getFoodPos().pos->x) {
                MacUILib_printf("%c", gameMechs->getFoodPos().getSymbol());                                         //*make food

            } else {
                bool drawn = false;
                for (int i = 0; i < player->getPlayerPos()->getSize(); i++) {           //*draw body
                    objPos temp = player->getPlayerPos()->getElement(i);

                    if (row == temp.pos->y && column == temp.pos->x) {

                        MacUILib_printf("%c", temp.getSymbol());
                        drawn = true;
                        break;
                    }
                }
                if (!drawn) {
                    MacUILib_printf(" ");           //*rest of board
                }
            }
        }
        MacUILib_printf("\n");
    }

    printf("Click enter to exit");
}

//^cleaned up the mess of a draw screen function it was giving me bain aids



void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete player;
    delete gameMechs;



    MacUILib_uninit();
}