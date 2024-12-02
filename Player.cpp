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
    foodPosList = new objPosArrayList();

    //*most recent comments for final iteration since I made a whole lota changes will be in green

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
///*fixed ur synta should be currhead.pos->y or x
    //int x = playerPos.pos->x;
    //int y = playerPos.pos->y;

    
    //it3
    objPos currentHead = playerPosList->getHeadElement(); // current head pos


    //^now to update each time the player moves (same as ppa3 just chaneg syntax):
    
    //replaced x and y with currhead.x and .y
    switch (myDir){
        case Dir::UP:
        currentHead.pos->y -= 1;
        break;
        case Dir::DOWN:
        currentHead.pos->y += 1;
        break;
        case Dir::LEFT:
        currentHead.pos->x-=1;
        break;
        case Dir::RIGHT:
        currentHead.pos->x +=1;
        break;
        case Dir::STOP:
        default:
        return;
    }
//^ gotta think of the wraparound a little differntly cuz of no height var so it's a bit diff
    int boardsizeX = mainGameMechsRef->getBoardSizeX(); //^both of these from game mech
    int boardsizeY = mainGameMechsRef->getBoardSizeY();

//*moved to keep track easier^


    if (currentHead.pos->y>=boardsizeY - 1){
        currentHead.pos->y=1;
    }
    else if (currentHead.pos->y<=0){
        currentHead.pos->y = boardsizeY-2;
    }

    if (currentHead.pos->x>=boardsizeX -1){
        currentHead.pos->x  =1;
    }
    else if (currentHead.pos->x<=0){
        currentHead.pos->x = boardsizeX-2;
    } 


//^ BE CAREFUL WITH CALLING THINGS you need an arrow operator not a dot operator.


    //playerPos.setObjPos(x,y,'*');

//iter3 insert head



    for (int i = 0; i < playerPosList->getSize();i++){  //*from 0 until we iterate thought size of snake
        auto element = playerPosList->getElement(i);    //*elemnt = the elelmtns of the snake (iterated to fil every space the snaek it taking)
        if (currentHead.isPosEqual(&element)){          //*check if the head overlaps with the body
            mainGameMechsRef->setLoseFlag();            //* setloseflag.. c uz thats how we lose in snake
            return;
        }
    }

    playerPosList->insertHead(currentHead);         //*similar to waht you had just needed to change things a little so I was using plater stuff nto game mech cuz it was glitchy.
    if (!growSnake) {
        playerPosList->removeTail();
    } else {
        growSnake = false;

        //*I had to chaneg this cuz using the growthflag in gamemech's was causing some serious glitches (freezing all the time my anti virus was acting up lol)
        //* i made a new function to deal with it
        //*similar logic to food gen


    


  /*objPos newHead(currentHead.pos->x,currentHead.pos->y,'*');
    playerPosList->insertHead(currentHead);

    //remove tail
    if (!mainGameMechsRef->getGrowthFlag()){
    playerPosList->removeTail();
    }
    else{
        mainGameMechsRef->setGrowthFlag(false);
    }*/

    
}

}

// More methods to be added
//added 4 u <3 muah
//*merci ;) but i ended up making my own LOL

void Player::grow(){
    growSnake = true;
}

bool Player::checkCollisionFood(const objPos& foodPos) {

    objPos head = playerPosList->getHeadElement();
    return head.isPosEqual(&foodPos);
}