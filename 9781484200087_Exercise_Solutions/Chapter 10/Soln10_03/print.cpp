// Exercise 10.3 Using namespaces. The solution is as Exercise 10.2, with changes to
// print.h, print.cpp, printthis.cpp and printthat.cpp: 

// print.cpp
#include "print.h"
#include <string>
#include <iostream>
using std::string;

void print1::print(const string& s) 
{
  std::cout << s << " (Namespace name is print1.) " << std::endl;
}

void print2::print(const string& s) 
{
  std::cout << s << " (Namespace name is print2.) " << std::endl;
}