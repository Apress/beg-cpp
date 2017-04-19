// Ex13_02.cpp
// Calling base class constructors in a derived class constructor
#include <iostream>
#include "Box.h"                 // For the Box class
#include "Carton.h"              // For the Carton class

int main()
{
  // Create four Carton objects
  Carton carton1;
  Carton carton2 {"Thin cardboard"};
  Carton carton3 {4.0, 5.0, 6.0, "Plastic"};
  Carton carton4 {2.0, "paper"};

  std::cout << "carton1 volume is " << carton1.volume() << std::endl;
  std::cout << "carton2 volume is " << carton2.volume() << std::endl;
  std::cout << "carton3 volume is " << carton3.volume() << std::endl;
  std::cout << "carton4 volume is " << carton4.volume() << std::endl;
}
