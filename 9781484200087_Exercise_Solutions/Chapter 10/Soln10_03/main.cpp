// Exercise 10.3 Using a global variable to count calls to print().  File: main.cpp
// This file is the same as Ex 10.2. 

#include "printthis.h"
#include "printthat.h"

#include <iostream>                                                    // ADDED
extern int print_count = 0;                                            // Counts calls to print() ADDED

int main(){
  print_this("This is a test string using printthis().");
  print_that("This is a test string using printthat().");

  std::cout << "The print() function has been called a total of "      // ADDED
            << print_count << " times. " << std::endl;                 // ADDED
}