// Exercise 11.3 Integer.cpp
#include <iostream>
#include "Integer.h"
using std::endl;

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

Integer* Integer::add(const Integer& obj)
{ 
  n += obj.n;
  return this;
}

Integer* Integer::subtract(const Integer& obj) 
{
  n -= obj.n;
  return this;
}

Integer* Integer::multiply(const Integer& obj) 
{
  n *= obj.n;
  return this;
}

void Integer::show() {
  std::cout << "Value is " << n << std::endl;
}

// Compare function
/*
int Integer::compare(const Integer obj) const {
  if(n < obj.n)
    return -1;
  else if(n==obj.n)
    return 0;
  return 1;
}
*/

// Compare function with reference parameter
// /*
int Integer::compare(const Integer& obj) const {
  if(n < obj.n)
    return -1;
  else if(n==obj.n)
    return 0;
  return 1;
}
// */