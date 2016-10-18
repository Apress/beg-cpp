// Exercise 15.3 Implementing a terminate handler
// All we have to do is add the definition for our terminate handler function
// and set our terminate handler in place of the default in main()
// The class definitions are as for Ex 15.2
#include "CurveBall.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Terminate handler
void myHandler()
{
  std::cout << "My termination handler called." << std::endl;
  exit(1);
}

// Function to generate a random integer 0 to count-1
size_t random(size_t count)
{
  return static_cast<size_t>((count*static_cast<unsigned long>(rand())) / (RAND_MAX + 1UL));
}

// Throw a CurveBall exception 25% of the time
void sometimes()
{
  CurveBall e;
  if (random(20)<5)
    throw e;
}

// This program will  be terminated by the myHandler() function when the TooManyExceptions exception is thrown.
int main()
{
  std::srand((unsigned)std::time(0));            // Seed random number generator
  size_t number {1000};                          // Number of loop iterations
  size_t exceptionCount {};                      // Count of exceptions thrown
  TooManyExceptions eTooMany;                    // Exception object

  set_terminate(myHandler);                      // Install our own handler

  for (size_t i {}; i < number; ++i)
    try
  {
    sometimes();
  }
  catch (CurveBall& e)
  {
    std::cout << e.what() << std::endl;
    if (++exceptionCount > 10)
      throw eTooMany;
  }
}