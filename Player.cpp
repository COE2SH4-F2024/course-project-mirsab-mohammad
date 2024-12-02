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

    //it3
    playerPosList = new objPosArrayList();

    objPos headPos(thisGMRef->getBoardSizeX()/2,thisGMRef->getBoardSizeY()/2,'*');
    playerPosList->insertHead(headPos);

    // more actions to be included
    /*int boardWid = mainGameMechsRef->getBoardSizeX();
    int boardHei = mainGameMechsRef->getBoardSizeY();

    int starting_pos_x = boardWid/2;
    int starting_pos_y = boardHei/2;

    playerPos.setObjPos(starting_pos_x,starting_pos_y,'*');*/




} 


Player::~Player()
{
    // delete any heap members here
    //^ NONE YET??

    // there is now lil bro
    delete playerPosList;
}
//was objpos
objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the player objpos arrray list
    return playerPosList;
    // return playerpos
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

    //commented out bcuz i replaced all x and y vals with currhead.x and .y
    //int x = playerPos.pos->x;
    //int y = playerPos.pos->y;

    int boardsizeX = mainGameMechsRef->getBoardSizeX(); //^both of these from game mech
    int boardsizeY = mainGameMechsRef->getBoardSizeY();

    //it3
    objPos currentHead;
    playerPosList-> getHeadElement(currentHead); // current head pos

    //^now to update each time the player moves (same as ppa3 just chaneg syntax):
    
    //replaced x and y with currhead.x and .y
    switch (myDir){
        case Dir::UP:
        currentHead.y -= 1;
        break;
        case Dir::DOWN:
        currentHead.y += 1;
        break;
        case Dir::LEFT:
        currentHead.x-=1;
        break;
        case Dir::RIGHT:
        currentHead.x +=1;
        break;
        case Dir::STOP:
        default:
        return;
    }
//^ gotta think of the wraparound a little differntly cuz of no height var so it's a bit diff
    if (currentHead.y>=boardsizeY - 1){
        currentHead.y=1;
    }
    else if (currentHead.y<=0){
        currentHead.y = boardsizeY-2;
    }

    if (currentHead.x>=boardsizeX -1){
        currentHead.x  =1;
    }
    else if (currentHead.x<=0){
        currentHead.x =boardsizeX-2;
    } 

    //playerPos.setObjPos(x,y,'*');

//iter3 insert head
    playerPosList->insertHead(currentHead);

    //remove tail
    playerPosList->removeTail();
}

// More methods to be added
//added 4 u <3 muah

bool player:: checkFoodConsumption() {

}

void increasePlayerLength() {

}

bool checkSelfCollision() {

}