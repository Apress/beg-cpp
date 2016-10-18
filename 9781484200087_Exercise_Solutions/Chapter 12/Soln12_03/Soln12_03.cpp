// Ex12.3
// Implementing the / operator for the Box class
// to allow one Box object to be divides into another.
#include <iostream>
#include "Box.h"

int main()
{
  Box box1 {12, 5, 12};
  Box box2 {3, 4, 5};
  Box box3 {3, 4, 7};
  std::cout << "box1 is " << box1 << std::endl;
  std::cout << "box2 is " << box2 << std::endl;
  std::cout << "box3 is " << box3 << std::endl;
  std::cout << "box1/box2 is " << box1 / box2 << std::endl;
  std::cout << "box2/box3 is " << box2 / box3 << std::endl;
  std::cout << "box1/box3 is " << box1 / box3 << std::endl;
  std::cout << "(box1+2*box2)/box3 is " << (box1 + 2 * box2) / box3 << std::endl;
}

