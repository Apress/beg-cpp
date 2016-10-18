// Exercise 17.1 Using the Time class with an overloaded insertion operator.

#include "Time.h"
#include <iostream>

int main()
{
  Time period1(10,30,25);
  Time period2(1, 70,90);
  std::cout << "\nPeriod 1 is " << period1
            << "\nPeriod 2 is " << period2
            << std::endl;
}