// Stack.h Templates to define stacks
#ifndef STACKS_H
#define STACKS_H
#include <stdexcept>

template <typename T>
class Stack
{
  private:
    // Nested class
    class Node 
    {
      public:
        T* pItem {};                           // Pointer to object stored
        Node* pNext {};                        // Pointer to next node

        Node(T& item) : pItem {&item} {}       // Create a node from an object
    };

    Node* pHead {};                            // Points to the top of the stack
    void copy(const Stack& stack);             // Helper to copy a stack
    void freeMemory();                         // Helper to release free store memory

  public:
    Stack() = default;                         // Default constructor
    Stack(const Stack& stack);                 // Copy constructor
    ~Stack();                                  // Destructor
    Stack& operator=(const Stack& stack);      // Assignment operator

    void push(T& item);                        // Push an object onto the stack
    T& pop();                                  // Pop an object off the stack
    bool isEmpty() {return !pHead;}            // Empty test
};

// Copy constructor
template <typename T>
Stack<T>::Stack(const Stack& stack)
{
  copy(stack);
}

// Helper to copy a stack
template <typename T>
void Stack<T>::copy(const Stack& stack)
{
  if(stack.pHead)
  {
    pHead = new Node {*stack.pHead};           // Copy the top node of the original
    Node* pOldNode {stack.pHead};              // Points to the top node of the original
    Node* pNewNode {pHead};                    // Points to the node in the new stack

    while(pOldNode = pOldNode->pNext)          // If it's nullptr, it's the last node
    {     
      pNewNode->pNext = new Node {*pOldNode};  // Duplicate it
      pNewNode = pNewNode->pNext;              // Move to the node just created
    }
  }
}

// Assignment operator
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& stack)
{
  if (this != &stack)                          // If objects are not identical
  {
    freeMemory();                              // Release memory for nodes in lhs
    copy(stack);                               // Copy rhs to lhs
  }
  return *this                                 // Return the left object
}

// Helper to release memory for a stack
template <typename T>
void Stack<T>::freeMemory()
{
  Node* pTemp {};
  while(pHead)
  {                                            // While current pointer is not null
    pTemp = pHead->pNext;                      // Get the pointer to the next
    delete pHead;                              // Delete the current
    pHead = pTemp;                             // Make the next current
  }
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
  freeMemory();
}

// Push an object onto the stack
template <typename T>
void Stack<T>::push(T& item)
{
  Node* pNode {new Node(item)};                // Create the new node
  pNode->pNext = pHead;                        // Point to the old top node
  pHead = pNode;                               // Make the new node the top
}

// Pop an object off the stack
template <typename T>
T& Stack<T>::pop()
{
  T* pItem {pHead->pItem};                     // Get pointer to the top node object
  if(!pItem)                                   // If it's empty
    throw std::logic_error {"Stack empty"};    // Pop is not valid so throw exception

  Node* pTemp {pHead};                         // Save address of top node
  pHead = pHead->pNext;                        // Make next node the top
  delete pTemp;                                // Delete the previous top node
  return *pItem;                               // Return the top object
}
#endif
