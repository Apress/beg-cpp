// Exercise 10.1 Using multiple files and preprocessor directives.  File: print.h
// We have seven files in all. 
// The file print.h contains the prototype for the function print().

#ifndef PRINT_H
#define PRINT_H

#include <string>
using std::string;

// Function prototype
void print(const string& s);

#endif