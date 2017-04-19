// Box.h
#ifndef BOX_H
#define BOX_H
#include <iostream>

class  Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Constructors
  Box(double lv, double wv, double hv);

  Box(double side) : Box {side, side, side}                            // Constructor for a cube
  {
    std::cout << "Box constructor 2 called." << std::endl;
  }

  Box()                                                               // No-arg constructor
  {
    std::cout << "No-arg Box constructor called." << std::endl;
  }

  Box(const Box& box)                                                 // Copy constructor
    : length {box.length}, width {box.width}, height {box.height}
  {
    std::cout << "Box copy constructor called." << std::endl;
  }

  double volume() const;                            // Function to calculate the volume of a box
};
#endif
