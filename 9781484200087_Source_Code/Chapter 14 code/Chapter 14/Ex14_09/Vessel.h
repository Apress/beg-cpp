// Vessel.h  Abstract class defining a vessel
#ifndef VESSEL_H
#define VESSEL_H
#include <iostream>

class  Vessel
{
public:
  virtual double volume() const = 0;

  ~Vessel() { std::cout << "Vessel  destructor" << std::endl; }
  // virtual ~Vessel() { std::cout << "Vessel  destructor" << std::endl; }
};
#endif
