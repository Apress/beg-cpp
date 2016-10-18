// Exercise 10.4 This file is the same as for Exercise 10.3. 

// print.cpp
#include "print.h"
#include <string>
#include <iostream>
using std::string;

void print1::print(const string& s) {
  std::cout << s << " (Namespace name is print1.) " << std::endl;
}

void print2::print(const string& s) {
  std::cout << s << " (Namespace name is print2.) " << std::endl;
}