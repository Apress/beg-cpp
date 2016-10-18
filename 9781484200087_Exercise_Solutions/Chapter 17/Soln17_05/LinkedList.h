#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include <memory>
#include "Box.h"
using PBox = std::shared_ptr < Box > ;

class LinkedList
{
  class Node;                                                // Declaration required because class is not yet defined
  using PNode = std::shared_ptr<Node>;                       // and we reference it here

  // Stream extraction and insertion
  friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
  friend std::istream& operator>>(std::istream& in, LinkedList& list);

private:
  PNode pHead {};                                            // Pointer to first element node
  PNode pTail {};                                            // Pointer to last element node
  PNode pLast {};                                            // Pointer to last node accessed

public:
  LinkedList() = default;                                     // Constructor
  LinkedList(const LinkedList& list);                         // Copy constructor
  LinkedList& operator=(const LinkedList& list);              // Assignment operator
  void addHead(Box& box);                                     // Add a Box object to the head
  void addTail(Box& box);                                     // Add an object to the tail
  Box getHead();                                              // Get the object at the head
  Box getTail();                                              // Get the object at the head
  Box getNext();                                              // Get the next object
  Box getPrevious();                                          // Get the previous object

private:
  // Node class definition
  class Node
  {
  public:
    PBox pBox {};                                             // Pointer to Box object
    PNode pNext {};                                           // Pointer to next node
    PNode pPrevious {};                                       // Pointer to previous node

    Node(Box& box) : pBox {std::make_shared<Box>(box)} {}                 // Constructor
    Node(const Node& node) : pBox {std::make_shared<Box>(*node.pBox)} {}  // Copy constructor
  };
};

// Stream insertion operator
inline std::ostream& operator<<(std::ostream& out, LinkedList& list)
{
  Box box {list.getHead()};
  while (true)
  {
    if (typeid(out) == typeid(std::ofstream))                               // Only write the flag if it is a file stream
    out << (box != nullBox) << ' ';
    if (box == nullBox)
      break;
    out << box;
    box = list.getNext();
  }
  return out;
}

// Stream extraction operator
inline std::istream& operator>>(std::istream& in, LinkedList& list)
{
  bool isBox {};
  Box box;
  while (true)
  {
    in >> isBox;                     // Read the flag indicating a Box follows
    if (!isBox)                      // If there's no Box...
      break;                         // ...we are done
    in >> box;                       // Read a Box...
    list.addTail(box);               // ...and add it to the list
  }
  return in;
}

#endif                              //LINKEDLIST_H