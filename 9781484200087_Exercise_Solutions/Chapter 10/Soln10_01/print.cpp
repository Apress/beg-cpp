// Exercise 10.1 Using multiple files and preprocessor directives.  File: print.cpp
// We have seven files in all. 
// The file print.cpp contains the definition for the function print().

#include "print.h"
#include <string>
#include <iostream>
using std::string;

void print(const string& s)
{
  std::cout << s << std::endl;
}