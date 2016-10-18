// Exercise 10.2 Using multiple files and preprocessor directives.  File: printthat.cpp
// We have seven files in all. 
// The file printthat.cpp contains the definition for the function printthat().
// Each of the files printthis.cpp and printthat.cpp must #include the file print.h,
// as well as its own header file: 
#include "printthat.h"
#include "print.h"

void print_that(const string& s)
{
  print(s);
}