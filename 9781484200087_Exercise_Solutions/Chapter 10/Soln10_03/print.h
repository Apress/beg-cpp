// Exercise 10.3 Using namespaces. The solution is as Exercise 10.2, with changes to
// print.h, print.cpp, printthis.cpp and printthat.cpp: 

// print.h
#ifndef PRINT_H
#define PRINT_H

#include <string>
using std::string;

namespace print1 
{
  // Function prototype
  void print(const string& s);
}

namespace print2 
{
  // Function prototype
  void print(const string& s);
}

#endif