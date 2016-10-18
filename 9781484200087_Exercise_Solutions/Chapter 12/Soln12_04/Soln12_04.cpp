// Ex12.4
// Implementing the % operator for the Box class
// to produce the volume left after dividing one Box object into another.
// This corresponds to the unoccupied space when the maximum number of smaller boxes
// are packed into the larger box.
#include <iostream>
#include "Box.h"

int main()
{
  Box box1 {12, 5, 12};
  Box box2 {3, 4, 5};
  Box box3 {5, 4, 5};
  std::cout << "box1 is " << box1 << std::endl;
  std::cout << "box2 is " << box2 << std::endl;
  std::cout << "Volume of box1 is " << box1.volume() << std::endl;
  std::cout << "Volume of box2 is " << box2.volume() << std::endl;

  size_t n {box1 / box2};
  std::cout << "box1/box2 is " << n << std::endl;
  std::cout << "With " << n << " of box2 in box1, the space left is " << box1%box2 << std::endl;

  n = box1 / box3;
  std::cout << "box1/box3 is " << n << std::endl;
  std::cout << "With " << n << " of box3 in box1, the space left is " << box1%box3 << std::endl;
}

