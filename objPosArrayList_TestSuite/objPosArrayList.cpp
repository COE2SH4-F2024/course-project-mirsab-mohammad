#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

/*
^leaving this big chunk here this is all test and I have test cases so I can confirm then copy paste into actual project
^the manual is my best friend here the visuals help a lot, refger to any of ur diagrams too on your ipad and stuff
^ALSO READ THROUGH THE SKELETON CODE AND UNDERSTAND YOUR VARIABLES AND WHAT NOT SO YOU DON'T ALT TABB ALL THE TIME
*/



//^ CONSTRUCTOR (under comment)
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; //Make big
    aList = new objPos[arrayCapacity]; //allocation (copy)
    listSize = 0; //initilize all 0's
}


//^ Destructor
objPosArrayList::~objPosArrayList()
{
delete[] aList; //^ FREE MA BOI

}

int objPosArrayList::getSize() const
{
return listSize;
//^freebie
}

void objPosArrayList::insertHead(objPos thisPos)
{
 if (listSize >= arrayCapacity){
    throw std::cout("Error with max capacity"); //^this is just an error check to make sure I don't go above the array capacity
    return;
 }
 for (int i = listSize; i > 0; i--){
    aList[i] = aList[i-1];
 }   

 //^literally just making the the head (everything follows it so start at i and increment down *the body* of the snake)

aList[0] = thisPos;
listSize++;

//^ after we 



}

void objPosArrayList::insertTail(objPos thisPos)
{
    
}

void objPosArrayList::removeHead()
{
    
}

void objPosArrayList::removeTail()
{
    
}

objPos objPosArrayList::getHeadElement() const
{
    
}

objPos objPosArrayList::getTailElement() const
{
    
}

objPos objPosArrayList::getElement(int index) const
{
    
}