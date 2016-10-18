// Exercise 11.1 Integer.cpp

#include <iostream>
#include "Integer.h"

Integer::Integer(int m)
{
  n = m;
  std::cout << "Object created." << std::endl;
}

void Integer::show()
{
  std::cout << "Value is " << n << std::endl;
}