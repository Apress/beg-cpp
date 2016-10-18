// Exercise 15.3 CurveBall.h
// Definition of CurveBall and TooManyExceptions exception classes

#ifndef CURVEBALL_H
#define CURVEBALL_H
#include <exception>

class CurveBall : public std::exception
{
public:
  const char* what() const;
};

class TooManyExceptions : public std::exception
{
public:
  const char* what() const;
};

#endif //CURVEBALL_H