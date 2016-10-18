// Exercise 10.3 Using namespaces. The solution is as Exercise 10.2, with changes to
// print.h, print.cpp, printthis.cpp and printthat.cpp: 

// printthat.cpp
#include "printthat.h"
#include "print.h"

void print_that(const string& s)
{
  print2::print(s);
}