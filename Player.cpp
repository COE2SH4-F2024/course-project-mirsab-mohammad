#include "Player.h"
#include "MacUILib.h"
#include "GameMechs.h"

/*
^adding this for myself (mirsab)
^ I need to 
*/



Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    int boardWid = mainGameMechsRef->getBoardSizeX();
    int boardHei = mainGameMechsRef->getBoardSizeY();

    int starting_pos_x = boardWid/2;
    int starting_pos_y = boardHei/2;

    playerPos.setObjPos(starting_pos_x,starting_pos_y,'*');




}


Player::~Player()
{
    // delete any heap members here
    //^ NONE YET??
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
    //^ easy?
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic          

        char input = mainGameMechsRef->getInput(); //^ this gets the input (iteration 1b)

        //^ just translate c --> c++ not too bad just hope I don't miss anything cuz my ppa3 is a mess, check each one making sure we aint going backwards and go that direction

        if ((input == 'w'  || input == 'W') && myDir!= Dir::DOWN){
            myDir = Dir::UP;
        }
        else if ((input == 's' || input =='S') && myDir != Dir::UP){
            myDir = Dir::DOWN;
        }
        else if ((input == 'a' || input =='A') && myDir != Dir::RIGHT){
            myDir = Dir::LEFT;
        }
        else if ((input == 'd' || input =='D') && myDir != Dir::LEFT){
            myDir = Dir::RIGHT;
        }

        mainGameMechsRef ->clearInput();
        //^ get rid of the input after (iteration 1b) as well.


}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int x = playerPos.pos->x;
    int y = playerPos.pos->y;

    int boardsizeX = mainGameMechsRef->getBoardSizeX(); //^both of these from game mech
    int boardsizeY = mainGameMechsRef->getBoardSizeY();

    //^now to update each time the player moves (same as ppa3 just chaneg syntax):

    switch (myDir){
        case Dir::UP:
        y -= 1;
        break;
        case Dir::DOWN:
        y += 1;
        break;
        case Dir::LEFT:
        x-=1;
        break;
        case Dir::RIGHT:
        x +=1;
        break;
        case Dir::STOP:
        default:
        return;
    }
//^ gotta think of the wraparound a little differntly cuz of no height var so it's a bit diff
    if (y>=boardsizeY - 1){
        y=1;
    }
    else if (y<=0){
        y = boardsizeY-2;
    }

    if (x>=boardsizeX -1){
        x  =1;
    }
    else if (x<=0){
        x =boardsizeX-2;
    }

    playerPos.setObjPos(x,y,'*');
}

// More methods to be added