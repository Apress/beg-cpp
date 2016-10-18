// Exercise 10.2 Using multiple files and preprocessor directives.  File: printthis.cpp
// We have seven files in all. 
// The file printthis.cpp contains the definition for the function printthis().
// Each of the files printthis.cpp and printthat.cpp must #include the file print.h,
// as well as its own header file: 
#include "printthis.h"
#include "print.h"

void print_this(const string& s)
{
  print(s);
}