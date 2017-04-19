// Ex15_08.cpp
// Using an exception class
#include <iostream>
#include "Box.h"                            // For the  Box class
#include "Dimension_error.h"                // For the  dimension_error  class

int main()
try
{
  Box box1 {1.0, 2.0, 3.0};
  std::cout << "box1 volume is " << box1.volume() << std::endl;
  Box box2 {1.0, -2.0, 3.0};
  std::cout << "box1 volume is " << box2.volume() << std::endl;
}
catch (std::exception& ex)
{
  std::cout << "Exception caught in main(): " << ex.what() << std::endl;
}