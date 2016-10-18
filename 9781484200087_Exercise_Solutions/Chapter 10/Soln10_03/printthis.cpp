// Exercise 10.3 Using namespaces. The solution is as Exercise 10.2, with changes to
// print.h, print.cpp, printthis.cpp and printthat.cpp: 

// printthis.cpp
#include "printthis.h"
#include "print.h"

void print_this(const string& s)
{
  print1::print(s);
}