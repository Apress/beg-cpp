// Truckload.h
#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <memory>
#include <vector>
template <typename T> using ptr = std::shared_ptr<T>;

class  Truckload
{
private:
  // Package is private to the Truckload class
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
  void listBoxes();                                // Output the Boxes
};
#endif

