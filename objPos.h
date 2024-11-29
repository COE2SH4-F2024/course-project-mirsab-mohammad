#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos(); //^ this is the def constructor
        objPos(int xPos, int yPos, char sym); //^param
        

        //^R4/6 --> I need copy construct and copy assingment also destructor too
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        objPos(const objPos& other); //^copy c
        objPos& operator = (const objPos& other); //^copy assign
        ~objPos(); // ^destructor 
        

        /*
        ^this stuff makes no sense literally following the TODO and what lecture said 
    
        */
        

        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif