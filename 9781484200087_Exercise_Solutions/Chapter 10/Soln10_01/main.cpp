// Exercise 10.1 Using multiple files and preprocessor directives.  File: main.cpp
// We have seven files in all. 
// The file main.cpp only needs to #include  two of our three new header files,
// since all it does is call the functions printthis() and printthat():

#include "printthis.h"
#include "printthat.h"

int main()
{
  print_this("This is a test string using printthis().");
  print_that("This is a test string using printthat().");
}