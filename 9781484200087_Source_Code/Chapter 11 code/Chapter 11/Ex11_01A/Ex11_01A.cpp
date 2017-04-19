// Ex11_01A.cpp
// Defining a class constructor
#include  <iostream>
#include  "Box.h"

int main()
{
  Box  firstBox {80.0, 50.0, 40.0};             // Create a box
  double firstBoxVolume{firstBox.volume()};     // Calculate   the box  volume
  std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;
}
