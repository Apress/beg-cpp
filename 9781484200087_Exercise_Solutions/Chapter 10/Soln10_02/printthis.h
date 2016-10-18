// Exercise 10.2 Using multiple files and preprocessor directives.  File: printthis.h
// We have seven files in all. 
// The file printthis.h contains the prototype for the function print_this().

#ifndef PRINTTHIS_H
#define PRINTTHIS_H

#include <string>
using std::string;

// Function prototype
void print_this(const string& s);

#endif