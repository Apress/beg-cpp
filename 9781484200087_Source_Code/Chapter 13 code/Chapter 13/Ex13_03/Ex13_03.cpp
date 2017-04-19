// Ex13_03.cpp 
// Using a derived class copy constructor
#include <iostream>
#include "Box.h"                         // For the Box class
#include "Carton.h"                      // For the Carton class

int main()
{
  // Declare and initialize a Carton object
  Carton carton(20.0, 30.0, 40.0, "Glassine board");

  Carton cartonCopy(carton);             // Use copy constructor

  std::cout << "Volume of carton is " << carton.volume() << std::endl
    << "Volume of cartonCopy is " << cartonCopy.volume() << std::endl;
}
