// Exercise 10.4 Using multiple files and preprocessor directives.  File: printthis.h
// We have seven files in all. 
// This file printthis.h contains the prototype for the function print_this()
// and is the same as for Exercise 10.3.

#ifndef PRINTTHIS_H
#define PRINTTHIS_H

#include <string>
using std::string;

// Function prototype
void print_this(const string& s);

#endif