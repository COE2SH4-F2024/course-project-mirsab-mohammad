#include "objPos.h"
//^Default (1/4)
objPos::objPos() 
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

/*
^ adding a whole lot of stuff in this section (iteration 0)
^Gonna add a copy Constructor Function, a copy AO function, I could also add a move constructor and assignment (iirc course said it's beyond this class?)
^gonna double check since I learned how to anyways. leaving larger comments block to make note of comign back in case of memory issue.
*/

//^copy constructors 2nd (2/4)
objPos::objPos(const objPos& other){
    pos = new Pos;
    pos->x = other.pos->x;
    pos->y = other.pos->y;
    symbol=other.symbol;
}

//^now the copy assignment (3/4)
objPos& objPos::operator=(const objPos& other){
    if (this == &other) return *this;

    delete pos;

    pos = new Pos;
    pos->x = other.pos->x;
    pos->y = other.pos->y;
    symbol = other.symbol;
    //^ DEEP COPY

    return *this;
}


//^ LASTLY is the destrucor (4/4)
objPos::~objPos(){
    delete pos;
}




void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
