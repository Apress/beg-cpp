// Exercise 11.4 Integer.cpp

#include <iostream>
#include "Integer.h"

// Copy constructor
Integer::Integer(Integer& obj) : n(obj.n)
{
  std::cout << "Object created by copy constructor." << std::endl;
}

// Constructor
Integer::Integer(int m) : n(m)
{
  std::cout << "Object created." << std::endl;
}

void Integer::show()
{
  std::cout << "Value is " << n << std::endl;
}