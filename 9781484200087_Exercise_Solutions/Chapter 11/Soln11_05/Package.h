// Package.h
#ifndef PACKAGE_H
#define PACKAGE_H
#include <memory>
#include "Box.h"
template <typename T> using ptr = std::shared_ptr<T>;

class  Package
{
private:
  ptr<Box> pBox;                                                     // Pointer to the Box object
  ptr<Package> pNext;                                                // Pointer to the next Package
  ptr<Package> pPrevious;                                            // Pointer to the previous Package

public:
  Package(ptr<Box> pb) : pBox {pb}, pNext {}, pPrevious {} {}        // Constructor


  ptr<Box>& getBox()  { return pBox; }                               // Retrieve  the  Box pointer
  ptr<Package>& getNext() { return pNext; }                          // Get next Package address
  ptr<Package>& getPrevious() { return pPrevious; }                  // Get next Package address

  void  setNext(ptr<Package>& pPackage)                              // Point to next object
  {
    pNext = pPackage;
  }

  void  setPrevious(ptr<Package>& pPackage)                          // Point to previous object
  {
    pPrevious = pPackage;
  }
};
#endif
