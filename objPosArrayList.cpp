#include "objPosArrayList.h"
#include <iostream>

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.
//^USE LECTURE CONTENT!!!



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
delete[] aList; 

}

int objPosArrayList::getSize() const
{
return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
 if (listSize >= arrayCapacity){
    std::cout << "Error with max capacity (array list)"; //^this is just an error check to make sure I don't go above the array capacity
    return;
 }
 for (int i = listSize; i > 0; i--){
    aList[i] = aList[i-1];
 }   

 //^literally shifting things over for head room

aList[0] = thisPos;
listSize++;

// filling tin the last section the for loop doesent (> 0 and all dat)
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity){
      std::cout << "error with max capcaity (array list)"; //^ more error checkign in case I screw up
      return;
    }

    aList[listSize] = thisPos; //^put it in tails location
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize == 0){
      std::cout << "moe error array list be empty"; //^ error check for me again.
      return;
    }
    for (int i = 0; i < listSize -1; i++){
      aList[i] = aList[i+1];
    }
    listSize--;
}
//^nearly exact opposite of insert head, move things other way in array and decrement.

void objPosArrayList::removeTail()
{
    if (listSize == 0){
      std::cout << "error lsit be empty";
      return;
    }
   listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}