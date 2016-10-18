// Exercise 10.2 Using a global variable to count calls to print().  File: print.cpp
// Only this file and main.cpp are different from Ex 10.1. 

#include "print.h"
#include <string>
#include <iostream>
using std::string;

extern int print_count;      // ADDED

void print(const string& s)
{
  std::cout << s << std::endl;
  ++print_count;             // ADDED

}