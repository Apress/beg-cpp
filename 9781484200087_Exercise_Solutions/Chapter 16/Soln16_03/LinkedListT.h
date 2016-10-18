// Exercise 16.3 LinkedListT.h
/*
The LinkedList template uses smart pointers to manage Node objects.
This means a destructor is not required.
Raw pointers to objects are stored in the list and objects are copied in the free stored
so the nested Node class needs a destructor.
If the linked list could only store smart pointers, it could only be used for objects in the free store.
A raw pointer can pointer to either free store objects or automatic objects.
*/
#ifndef LINKEDLISTT_H
#define LINKEDLISTT_H
#include <memory>

template<typename T> class LinkedList
{
  class Node;                                                // Declaration required because class is not yet defined
  using PNode = std::shared_ptr<Node>;
private:
  PNode pHead {};                                            // Pointer to first element node
  PNode pTail {};                                            // Pointer to last element node
  PNode pLast {};                                            // Pointer to last node accessed

public:
  LinkedList() = default;                                    // Constructor
  LinkedList(const LinkedList& list);                        // Copy constructor
  LinkedList& operator=(const LinkedList& list);             // Assignment operator
  void addHead(T* pObj);                                     // Add an object to the head
  void addTail(T* pObj);                                     // Add an object to the tail
  T* getHead();                                              // Get the object at the head
  T* getTail();                                              // Get the object at the head
  T* getNext();                                              // Get the next object
  T* getPrevious();                                          // Get the previous object

private:
  // Node class definition
  class Node
  {
  public:
    size_t index {};                                          // Index of element
    T* pObject {};                                            // Reference to object
    PNode pNext {};                                           // Pointer to next node
    PNode pPrevious {};                                       // Pointer to previous node

    Node(T* pObj) : pObject {new T {*pObj}} {}                 // Constructor
    Node(const Node& node) : index {node.index}, pObject {new T {*node.pObject}} {}  // Copy constructor
 
    ~Node() { delete pObject; }                                // Destructor
  };
};


// Copy constructor template
template<typename T> LinkedList<T>::LinkedList(const LinkedList& list)
{
  if (list.pHead)
  {                                  // If there is a first element
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

// Assignment operator template
template<typename T> LinkedList<T>& LinkedList<T>::operator=(const LinkedList& list)
{
  if (this == &list)                                             // Check for rhs same as lhs
    return *this;

  PNode pCurrent;
  if (list.pHead)
  {
    pTail = pHead = std::make_shared<Node>(*list.pHead);
    Node* pTemp {};
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

// Template function member to add an object to the head of the list
template<typename T> void LinkedList<T>::addHead(T* pObj)
{
  if (pHead)
  {
    pHead->pPrevious = std::make_shared<Node>(pObj);
    pHead->pPrevious->pNext = pHead;
    pHead = pHead->pPrevious;
  }
  else
    pHead = pTail = std::make_shared<Node>(pObj);
  pLast = pHead;
}

// Template function member to add an object to the tail of the list
template<typename T> void LinkedList<T>::addTail(T* pObj)
{
  if (pTail)
  {
    pTail->pNext = std::make_shared<Node>(pObj);
    pTail->pNext->pPrevious = pTail;
    pTail = pTail->pNext;
  }
  else
    pHead = pTail = std::make_shared<Node>(pObj);
  pLast = pTail;
}

// Template function member to get the object at the head of the list
template<typename T> T* LinkedList<T>::getHead()
{
  pLast = pHead;
  if (pHead)
    return pHead->pObject;
  else
    return nullptr;
}

// Template function member to get the object at the tail of the list
template<typename T> T* LinkedList<T>::getTail()
{
  pLast = pTail;
  if (pTail)
    return pTail->pObject;
  else
    return nullptr;
}

// Template function member to get the next object
template<typename T> T* LinkedList<T>::getNext()
{
  if (pLast)
    if (pLast = pLast->pNext)
      return pLast->pObject;
  return nullptr;
}

// Template function member to get the previous object
template<typename T> T* LinkedList<T>::getPrevious()
{
  if (pLast)
    if (pLast = pLast->pPrevious)
      return pLast->pObject;
  return nullptr;
}

#endif //LINKEDLISTT_H