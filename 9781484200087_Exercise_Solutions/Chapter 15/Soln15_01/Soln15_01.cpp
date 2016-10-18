// Exercise 15.1 Throwing and catching CurveBalls
#include "CurveBall.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Function to generate a random integer 0 to count-1
size_t random(size_t count)
{
  return static_cast<size_t>((count*static_cast<unsigned long>(rand()))/(RAND_MAX+1UL));
}

// Throw a CurveBall exception 25% of the time
void sometimes()
{
  CurveBall e;
  if(random(20)<5)
    throw e;
}

int main() 
{
  std::srand((unsigned)std::time(0));            // Seed random number generator
  size_t number {1000};                          // Number of loop iterations
  size_t exceptionCount {};                      // Count of exceptions thrown

  for (size_t i {}; i < number; ++i)
  try
  {
    sometimes();
  }
  catch(CurveBall& e)
  {
    exceptionCount++;
  }
  std::cout << "CurveBall exception thrown " << exceptionCount << " times out of " << number << ".\n";
}