// Truckload.h
#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <memory>
#include <vector>
#include "Box.h"
template <typename T> using ptr = std::shared_ptr<T>;

class  Truckload
{
private:
  class  Package
  {
  public:
    ptr<Box> pBox;                                 // Pointer to the Box object
    ptr<Package> pNext;                            // Pointer to the next Package

    Package(ptr<Box> pb) : pBox {pb}, pNext {} {}  // Constructor
  };

  ptr<Package> pHead;                              // First in the list
  ptr<Package> pTail;                              // Last in the list
  ptr<Package> pCurrent;                           // Last retrieved from the list

public:
  Truckload() {}                                   // No-arg constructor empty truckload

  Truckload(ptr<Box> pBox)                         // Constructor - one Box
  {
    pHead = pTail = std::make_shared<Package>(pBox);
  }

  Truckload(const std::vector< ptr<Box> >& boxes); // Constructor - vector of Boxes

  ptr<Box> getFirstBox();                          // Get the first Box
  ptr<Box> getNextBox();                           // Get the next Box
  void  addBox(ptr<Box> pBox);                     // Add a new Box
  bool deleteBox(ptr<Box> pBox);                   // Delete a Box
  ptr<Box> operator[](size_t index) const;         // Overloaded subscript operator

  friend std::ostream& operator<<(std::ostream& stream, Truckload& load);
};

// Subscript operator
inline ptr<Box> Truckload::operator[](size_t index) const
{
  ptr<Package> p {pHead};                          // Pointer to first Package
  size_t count {};                                 // Package count
  do {
    if (index == count++)                          // Up to index yet?
      return p->pBox;                              // If so return the pointer to Box
  } while (p = p->pNext);
  return nullptr;
}

// >> operator for output to a stream
inline std::ostream& operator<<(std::ostream& stream, Truckload& load)
{
  load.pCurrent = load.pHead;
  size_t count {};
  while (load.pCurrent)
  {
    std::cout << *(load.pCurrent->pBox);
    load.pCurrent = load.pCurrent->pNext;
    if (!(++count % 5)) std::cout << std::endl;
  }
  if (count % 5) std::cout << std::endl;
  return stream;
}

#endif

