// Exercise 10.1 Using multiple files and preprocessor directives.  File: printthat.h
// We have seven files in all. 
// The file printthat.h contains the prototype for the function print_that().
#ifndef PRINTTHAT_H
#define PRINTTHAT_H

#include <string>
using std::string;

// Function prototype
void print_that(const string& s);

#endif