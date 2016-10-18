// Truckload.h
#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <memory>
#include <vector>
#include "Package.h"

class  Truckload
{
private:
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
  ptr<Box> getLastBox();                           // Get the last Box
  ptr<Box> getNextBox();                           // Get the next Box
  ptr<Box> getPreviousBox();                       // Get the previous Box
  void  addBox(ptr<Box> pBox);                     // Add a new Box
  bool deleteBox(ptr<Box> pBox);                   // Delete a Box
  void listBoxes(bool forward=true);               // Output the Boxes - false for backwards
};
#endif

