// Box.cpp
#include  <iostream>
#include  "Box.h"

// Constructor definition
Box::Box(double  lengthValue, double widthValue, double heightValue)
{
  std::cout << "Box constructor called." << std::endl;
  length = lengthValue;
  width = widthValue;
  height = heightValue;
}

Box::Box() {}                                    // No-arg constructor

// Function to calculate the  volume of  a box
double Box::volume()
{
  return length*width*height;
}
