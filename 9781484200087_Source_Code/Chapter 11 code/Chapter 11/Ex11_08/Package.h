// Package.h
#ifndef PACKAGE_H
#define PACKAGE_H
#include <memory>
#include "Box.h"
template <typename T> using ptr = std::shared_ptr<T>;

class  Package
{
private:
  ptr<Box> pBox;                                   // Pointer to the Box object
  ptr<Package> pNext;                              // Pointer to the next Package

public:
  Package(ptr<Box> pb) : pBox {pb}, pNext {} {}    // Constructor

  ptr<Box>& getBox()  { return pBox; }             // Retrieve  the  Box pointer
  ptr<Package>& getNext() { return pNext; }        // Get next Package address

  void  setNext(ptr<Package>& pPackage)             // Point to next object
  {
    pNext = pPackage;
  }
};
#endif
