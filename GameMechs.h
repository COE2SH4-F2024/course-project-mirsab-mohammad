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

//<<<<<<< HEAD
        void generateFood(const objPosArrayList* playerList); //*changed this to accept playerlist as well
        objPos getFoodPos() const;

        char getBorderCharacter() const; // getter
        void setBorderCharacter(char c); // setter for it
        //^ADDED A COUPEL TO MAKE DRAW SCREEN MORE MODULE
//>>>>>>> 1ae6bd396d44ee186850493062aa387c465833d9


        void setGrowthFlag();
        bool getGrowthFlag() const;
        //^ setter and getter methods for grwoth flag (how we trackin growth?)






};





#endif