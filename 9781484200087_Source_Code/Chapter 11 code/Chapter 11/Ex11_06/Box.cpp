// Box.cpp
#include  <iostream>
#include  "Box.h"

size_t Box::objectCount {};                 // Initialize static member of Box class to 0

// Constructor definition
Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv}
{
  ++objectCount;
  std::cout << "Box constructor 1 called." << std::endl;
}

// Function to calculate the  volume of  a box
double Box::volume() const
{
  return length*width*height;
}
