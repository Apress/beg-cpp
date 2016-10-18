// Exercise 17.2 Using the Time class with an overloaded extraction operator.
// The extraction operator is implemented as a friend of the Time class
#include "Time.h"
#include <iostream>

int main()
{
  Time period1;
  Time period2;
  std::cout << "\nEnter a time as hours:minutes:seconds, and press Enter: ";
  std::cin >> period1;
  std::cout << "\nEnter another time as hours:minutes:seconds, and press Enter: ";
  std::cin >> period2;
  std::cout << "\nPeriod 1 is " << period1
            << "\nPeriod 2 is " << period2
            << std::endl;
}