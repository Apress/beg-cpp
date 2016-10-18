// Exercise 10.4 More applications of preprocessor directives. 

// main.cpp
#include "printthis.h"
#include "printthat.h"

//#define DO_THIS                                                      // uncomment to #define the token

#ifdef DO_THIS
#define PRINT(val) print_this(#val);
#else 
#define PRINT(val) print_that(#val);
#endif

int main() 
{
#ifdef DO_THIS
  print_this("This is a test string using printthis().");
#else 
  print_that("This is a test string using printthat().");
#endif

  std::cout << "The print() function has been called a total of "      // ADDED
            << print_count << " times. " << std::endl;                 // ADDED
}