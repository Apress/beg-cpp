#include "LinkedList.h"
#include <iostream>

// Copy constructor
LinkedList::LinkedList(const LinkedList& list)
{
  if (list.pHead)
  {                                                              // If there is a first element
    pTail = pHead = std::make_shared<Node>(*list.pHead);         // Duplicate it

    PNode pTemp;
    PNode pCurrent = list.pHead;
    while (pCurrent = pCurrent->pNext)
    {                                                            // Duplicate any further nodes
      pTemp = pTail;                                             // Save the address of the last
      pTail = std::make_shared<Node>(*pCurrent);                 // Make the new one the last
      pTemp->pNext = pTail;                                      // Set the next pointer of old last
      pTail->pPrevious = pTemp;                                  // Set previous pointer of new last 
    }
  }
}

// Assignment operator
LinkedList& LinkedList::operator=(const LinkedList& list)
{
  if (this == &list)                                             // Check for rhs same as lhs
    return *this;

  PNode pCurrent;
  if (list.pHead)
  {
    pTail = pHead = std::make_shared<Node>(*list.pHead);
    PNode pTemp {};
    pCurrent = list.pHead;
    while (pCurrent = pCurrent->pNext)
    {
      pTemp = pTail;
      pTail = std::make_shared<Node>(*pCurrent);
      pTemp->pNext = pTail;
      pTail->pPrevious = pTemp;
      pTemp = pTail;
    }
  }
  return *this;
}

// Add a Box object to the head of the list
void LinkedList::addHead(Box& box)
{
  if (pHead)
  {
    pHead->pPrevious = std::make_shared<Node>(box);
    pHead->pPrevious->pNext = pHead;
    pHead = pHead->pPrevious;
  }
  else
    pHead = pTail = std::make_shared<Node>(box);
  pLast = pHead;
}

// Add a Box object to the tail of the list
void LinkedList::addTail(Box& box)
{
  if (pHead)
  {
    pTail->pNext = std::make_shared<Node>(box);
    pTail->pNext->pPrevious = pTail;
    pTail = pTail->pNext;
  }
  else
    pHead = pTail = std::make_shared<Node>(box);
  pLast = pTail;
}

// Get the Box object at the head of the list
Box LinkedList::getHead()
{
  if (pHead)
  {
    pLast = pHead;
    return *pHead->pBox;
  }
  else
    return nullBox;
}

// Get the Box object at the tail of the list
Box LinkedList::getTail()
{
  pLast = pTail;
  if (pTail)
    return *pTail->pBox;
  else
    return nullBox;
}

// Get the next Box object
Box LinkedList::getNext()
{
  if (pLast)
    if (pLast = pLast->pNext)
      return *pLast->pBox;
  return nullBox;
}

// Get the previous Box object
Box LinkedList::getPrevious()
{
  if (pLast)
    if (pLast = pLast->pPrevious)
      return *pLast->pBox;
  return nullBox;
}
