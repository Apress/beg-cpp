// Exercise 2.2 This time, the user is also prompted to enter an integer that we can
// subsequently use to control the program's output. 
// Note that setprecision() doesn't alter the calculated value of areaOfCircle;
// it's only used to control how this value is output.

#include <iostream>
#include <iomanip>

int main()
{
  const float pi {3.14159f};                               // Initialize constant variable

  float radius {};
  float areaOfCircle {};
  unsigned int sigFigs {};

  std::cout << "This program will compute the area of a circle." << std::endl
            << "It assumes that the value of pi is " << pi << "." << std::endl;

  std::cout << "Please enter the radius: ";
  std::cin >> radius;

  std::cout << "Please enter the desired precision of the output (significant figures): ";
  std::cin >> sigFigs;

  areaOfCircle = pi * radius * radius;

  std::cout << "The area of the circle is approximately equal to "
            << std::setprecision(sigFigs)
            << areaOfCircle << " square units." << std::endl;
}