// Exercise 16.1 Exercising the SparseArray class template
// We create a sparse array of integers, populate 20 of its 
// entries (checking for duplicates among the randomly generated indices)
// and output the resulting index/value pairs.

// For practical use, the SparseArray template needs a mechanism for iteration over the elements that exist.
// Otherwise you could be executing a loop with several million iterations to access 10 elements with values.
// By now you should be able to see that this is not difficult to implement...

#include "SparseArrayT.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
using std::string;


// Function to generate a random integer 0 to count-1
int random(size_t count) 
{
  return static_cast<size_t>((count*static_cast<unsigned long>(rand()))/(RAND_MAX+1UL));
}

int main()
{
  SparseArray<int> numbers;                 // Create sparse array
  const size_t count {20};                  // Number of elements to be created
  size_t index {};                          // Stores new index value
  srand((unsigned)time(0));                 // Seed random number generator

  try
  {
    for (size_t i {}; i < count; ++i)       // Create count entries in numbers array
    {
      // Must ensure that indexes after the first are not duplicates
      for(;;) 
      {
        index = random(500);                // Get a random index 0 to 499
        if (numbers.element_exists(index)) continue;
        break;                              // We have a unique index
      }
      numbers[index] = 32+random(181);      // Store value at new index position
    }
  }
  catch(std::exception& e)
  {
    std::cout << "\nException thrown " << e.what() << std::endl;
  }
  numbers.show();
}