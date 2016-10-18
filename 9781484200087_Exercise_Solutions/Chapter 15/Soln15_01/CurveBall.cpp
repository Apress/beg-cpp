// Exercise 15.1 CurveBall.cpp
// Implementation of CurveBall exception class

#include "CurveBall.h"

const char* CurveBall::what() const
{
  return "CurveBall exception";
}