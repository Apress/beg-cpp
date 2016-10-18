// Exercise 15.3 CurveBall.cpp
// Implementation of CurveBall and TooManyExceptions exception classes

#include "CurveBall.h"

const char* CurveBall::what() const
{
  return "CurveBall exception";
}

const char* TooManyExceptions::what() const
{
  return "TooManyExceptions exception";
}