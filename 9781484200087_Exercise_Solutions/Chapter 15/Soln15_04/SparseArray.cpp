// Exercise 15.4 SparseArray.cpp
// Implementation of the SparseArray class

#include "SparseArray.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>

// Copy constructor
SparseArray::SparseArray(const SparseArray& array)
{
  maxElements = array.maxElements;                                   // Copy max element count

  if(array.pFirst)                                                   // If there is a first element...
  {                   
    pLast = pFirst = std::make_shared<Element>(*array.pFirst);       //  ...duplicate it

    PElement pTemp;
    PElement pCurrent = array.pFirst;
    while(pCurrent = pCurrent->pNext)                                // Duplicate any further elements
    {
      pTemp = pLast;                                                 // Save the address of the last
      pLast = std::make_shared<Element>(*pCurrent);                  // Make the new one the last
      pTemp->pNext = pLast;                                          // Set the next pointer of old last
      pLast->pPrevious = pTemp;                                      // Set previous pointer of new last
    }
  }
  else
    pLast = pFirst = nullptr;
}


// Assignment operator
SparseArray& SparseArray::operator=(const SparseArray& array)
{
   if(this == &array)                                                // Check for rhs same as lhs
    return *this;

  maxElements = array.maxElements;
  PElement pCurrent;
  if(array.pFirst)
  {
    pLast = pFirst = std::make_shared<Element>(*array.pFirst);
    PElement pTemp;
    pCurrent = array.pFirst;
    while(pCurrent = pCurrent->pNext)
    {
      pTemp = pLast;
      pLast = std::make_shared<Element>(*pCurrent);
      pTemp->pNext = pLast;
      pLast->pPrevious = pTemp;
      pTemp = pLast;
    }
  }
  else
    pLast = pFirst = nullptr;
  return *this;
}

// Subscript operator for non-const objects
SparseArray::Element& SparseArray::operator[](size_t index) 
{
  if(index >= maxElements) 
  {      // Out of range index
    string message {"Invalid index in SparseArray: "};
    message = message + std::to_string(index) + "\nIndex limits are 0 to " + std::to_string(maxElements - 1);
    throw std::out_of_range(message);
  }

  // Search the list for a Element corresponding to index
  PElement pCurrent = pFirst;
  while(pCurrent)
  {
    if(pCurrent->index == index)
      return *pCurrent;
    if(pCurrent->index > index)
      break;
    pCurrent = pCurrent->pNext;
  }

  // If we get to here, the element doesn't exist
  // so we must create one
  PElement pElement = std::make_shared<Element>(index);
  if(pCurrent) 
  { // It's not the end of the list so we must insert the element
    if(pCurrent->pPrevious) 
    { // Current has a previous Element so just insert the new Element between the two   
      pCurrent->pPrevious->pNext = pElement;
      pElement->pPrevious = pCurrent->pPrevious;
      pCurrent->pPrevious = pElement;
      pElement->pNext = pCurrent;
    }
    else 
    { // Current must be the first so add new Element as first
      pElement->pNext = pCurrent;
      pCurrent->pPrevious = pElement;
      pFirst = pElement;
    }
  }
  else 
  { // We are at the end of the list so we must append the new element
    if(pLast) 
    { // This is a last element so add it after that
      pLast->pNext = pElement;
      pElement->pPrevious = pLast;
      pLast = pElement;
    }
    else 
      pFirst = pLast = pElement;                                     // The list was empty
  }
  return *pElement;                                                  // Return the new element
}

// Display the elements of a SparseArray
void SparseArray::show() 
{
  PElement pCurrent = pFirst;
  while(pCurrent)
  {
    std::cout << "\n[" << std::setw(2) << pCurrent->index << "] = " 
              << std::fixed << std::setprecision(2) << pCurrent->value;
    pCurrent = pCurrent->pNext;
  }
  std::cout << std::endl;
}