// Exercise 16.1 SparseArrayT.h
// SparseArray class template definition
/*
The SparseArray template uses smart pointers to manage Node objects that are array elements.
This means a destructor is not required for SparseArray.
Raw pointers to objects are stored in the array and objects are copied in the free store
so the nested Node class needs a destructor.
If the sparse array could only store smart pointers, it could only be used for objects in the free store.
A raw pointer can pointer to either free store objects or automatic objects.
*/

#ifndef SPARSEARRAYT_H
#define SPARSEARRAYT_H
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
using std::string;


template<typename T> class SparseArray
{
  class Node;
  using PNode = std::shared_ptr < Node >;
private:
  PNode pFirst;                                              // Pointer to first element node
  PNode pLast;                                               // Pointer to last element node

public:
  SparseArray() = default;                                   // Constructor
  SparseArray(const SparseArray& array);                     // Copy constructor
  SparseArray& operator=(const SparseArray& array);          // Assignment operator
  T& operator[](size_t index);                               // Subscript SparseArray
  bool element_exists(size_t index);                         // Return true if element exists
  void show();                                               // display array elements

private:
  // Node class definition
  class Node
  {
  public:
    size_t index {};                       // Index of element
    T* pObject;                      // Address of object
    PNode pNext;                     // Pointer to next node
    PNode pPrevious;                 // Pointer to previous node

    Node(size_t newIndex) : index(newIndex), pObject(new T) {}                    // Constructor
    Node(const Node& node) : index(node.index), pObject(new T(*node.pObject)) {}  // Copy constructor
    ~Node(){ delete pObject; }                                                    // Destructor
  };
};


// Copy constructor template
template<typename T> SparseArray<T>::SparseArray(const SparseArray& array)
{
  if (array.pFirst)
  {                              // If there is a first element
    pLast = pFirst = std::make_shared<Node>(*array.pFirst);     // Duplicate it

    PNode pTemp;
    PNode pCurrent {array.pFirst};
    while (pCurrent = pCurrent->pNext)
    {                                                           // Duplicate any further nodes
      pTemp = pLast;                                            // Save the address of the last
      pLast = std::make_shared<Node>(*pCurrent);                // Make the new one the last
      pTemp->pNext = pLast;                                     // Set the next pointer of old last
      pLast->pPrevious = pTemp;                                 // Set previous pointer of new last
    }
  }
}

// Assignment operator template
template<typename T> SparseArray<T>& SparseArray<T>::operator=(const SparseArray& array)
{
  if (this == &array)                                           // Check for rhs same as lhs
    return *this;

  PNode pCurrent;
  if (array.pFirst)
  {
    pLast = pFirst = std::make_shared<Node>(*array.pFirst);
    Node* pTemp;
    pCurrent = array.pFirst;
    while (pCurrent = pCurrent->pNext)
    {
      pTemp = pLast;
      pLast = std::make_shared<Node>(*pCurrent);
      pTemp->pNext = pLast;
      pLast->pPrevious = pTemp;
      pTemp = pLast;
    }
  }
  return *this;
}

// Subscript operator for non-const objects
template<typename T> T& SparseArray<T>::operator[](size_t index)
{
  // Search the list for a node corresponding to index
  PNode pCurrent {pFirst};
  while (pCurrent)
  {
    if (pCurrent->index == index)
      return *pCurrent->pObject;
    if (pCurrent->index > index)
      break;
    pCurrent = pCurrent->pNext;
  }

  // If we get to here, the element doesn't exist
  // so we must create one
  PNode pNode = std::make_shared<Node>(index);
  pNode->pObject = new T;
  if (pCurrent)                                                 // If its not the end of the list we must insert the element
  {
    if (pCurrent->pPrevious)                                    // If current has a previous node just insert the new node   
    {
      pCurrent->pPrevious->pNext = pNode;
      pNode->pPrevious = pCurrent->pPrevious;
      pCurrent->pPrevious = pNode;
      pNode->pNext = pCurrent;
    }
    else                                                        // Current must be the first so add new node as first
    {
      pNode->pNext = pCurrent;
      pCurrent->pPrevious = pNode;
      pFirst = pNode;
    }
  }
  else 
  {                                                             // We must append the element
    if (pLast)
    {
      pLast->pNext = pNode;
      pNode->pPrevious = pLast;
      pLast = pNode;
    }
    else
      pFirst = pLast = pNode;
  }
  return *pNode->pObject;                                       // Return the new element
}

// Display the elements of a SparseArray
template<typename T> void SparseArray<T>::show()
{
  PNode pCurrent {pFirst};
  while (pCurrent)
  {
    std::cout << "\n[" << std::setw(2) << pCurrent->index << "] = " << *pCurrent->pObject;
    pCurrent = pCurrent->pNext;
  }
  std::cout << std::endl;
}

// Test for existence of element at index
template<typename T>
bool SparseArray<T>::element_exists(size_t index)
{
  PNode p {pFirst};
  while (p)
  {
    if (p->index == index) return true;
    p = p->pNext;
  }
  return false;
}

#endif //SPARSEARRAY_H