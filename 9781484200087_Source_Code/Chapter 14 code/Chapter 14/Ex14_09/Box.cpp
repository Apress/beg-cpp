// Box.cpp
// Global comparison operators for Box objects
#include "Box.h"

// Function comparing a constant with volume of a Box object
inline bool operator<(double aValue, const Box& aBox)
{
  return aValue < aBox.volume();
}
