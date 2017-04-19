#include <memory>                                             // For smart pointers
#include <vector>                                             // For vector<T>
#include "Box.h"
#include "Truckload.h"

// Constructor
Truckload::Truckload(const std::vector< ptr<Box> >& boxes)	   
{
  for (auto pBox : boxes)
  {
    addBox(pBox);
  }
}

// Add a Box to the list
void Truckload::addBox(ptr<Box> pBox)
{
  auto pPackage = std::make_shared<Package>(pBox);  // Create a Package

  if (pHead)                                        // Check  list is not  empty
    pTail->pNext = pPackage;                       // Add the  new  object  to  the  tail
  else                                              // List is empty
    pHead = pPackage;                               // so new  object  is the  head

  pTail = pPackage;                                 // Store  its address as tail
}

// Find the Package containing pBox and delete it from the list
bool Truckload::deleteBox(ptr<Box> pBox)
{
  pCurrent = pHead;                                 // Start at the first box
  ptr<Package> pPrevious;                           // There's no previous box to the 1st
  while (pCurrent)
  {
    if (pCurrent->pBox == pBox)                  // Check for identical Box pointers
    { // We found the box!
      if (pPrevious)                                 // If there's a previous box...
      {
        pPrevious->pNext = pCurrent->pNext;      // ...set its next to be the box after current
      }
      else                                            // It is the first box...
      {
        pHead = pHead->pNext;                     // ..so make the next the first box
      }
      pCurrent = nullptr;
      return true;
    }
    pPrevious = pCurrent;                             // Make current the previous box...
    pCurrent = pCurrent->pNext;                   // ... and the next one current
  }
  return false;
}

// Get the first Box
ptr<Box> Truckload::getFirstBox()				                   
{
  pCurrent = pHead->pNext;
  return pHead->pBox;
}

// Get the next Box
ptr<Box> Truckload::getNextBox()               
{
  if (!pCurrent)                                     // If there's no current...
    return getFirstBox();                            // ...return the 1st

  auto pPackage = pCurrent->pNext;               // Save the next package
  if (pPackage)                                      // If there is one...
  {
    pCurrent = pPackage;                             // Update current to the next                                  
    return pPackage->pBox;
  }
  pCurrent = nullptr;                                // If we get to here...
  return nullptr;                                    // ...there was no next
}
