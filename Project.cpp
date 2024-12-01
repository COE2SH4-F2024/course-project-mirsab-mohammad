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

    while(exitFlag == false)  
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



    //^pray this works ima kms if it don't
    MacUILib_init();
    MacUILib_clearScreen();

    gameMechs = new GameMechs(30,15); 
    player = new Player(gameMechs);

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
    player -> updatePlayerDir();

    player-> movePlayer();



}

void DrawScreen(void)

//^gonan cry if this doesen't work it should be easy but I'm spending so much time on this garbo.
{
    MacUILib_clearScreen();    
    int sizeX = gameMechs->getBoardSizeX();
    int sizeY = gameMechs->getBoardSizeY();

   
    for (int row = 0; row < sizeY; row++) {
        for (int column = 0; column < sizeX; column++) {
            if (row == 0 || column == 0 || row == sizeY - 1 || column == sizeX - 1) {
                MacUILib_printf("#");
            }
            else if (row == player->getPlayerPos().pos->y && column == player->getPlayerPos().pos->x) {
                MacUILib_printf("%c", player->getPlayerPos().getSymbol());
            }
            else {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n"); 
    }

}



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
