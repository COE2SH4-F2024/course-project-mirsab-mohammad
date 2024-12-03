#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;
    

        objPos foodPos;

        char borderCharacter;

        objPosArrayList* playerPosList;

        bool growthFlag;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput() ;
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        
        // More methods should be added here


        void generateFood(const objPosArrayList* playerList); //*changed this to accept playerlist as well
        objPos getFoodPos() const;

        char getBorderCharacter() const; // getter
        void setBorderCharacter(char c); // setter for it
        //^added these to make it more module



        void setGrowthFlag();//setter
        bool getGrowthFlag() const; //getter
        //^ I had issues with this so I think I used the player class one for a good chunk-ish.






};





#endif