// Exercise 2.1 Calculate the area of a circle of given radius. 
// The value of pi is constant, and should not be changed within the program,
// so we recognize this by declaring it as a const.

#include <iostream>

int main()
{
  
  const float pi {3.14159f};                               // Initialize constant variable

  float radius {};
  float areaOfCircle {};

  std::cout << "This program will compute the area of a circle." << std::endl
            << "It assumes that the value of pi is " << pi << "." << std::endl;

  std::cout << "Please enter the radius: ";
  std::cin >> radius;

  areaOfCircle = pi * radius * radius;

  std::cout << "\nThe area of the circle is " << areaOfCircle << " square units." << std::endl;
}