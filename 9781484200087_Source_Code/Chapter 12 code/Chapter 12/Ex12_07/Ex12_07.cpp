// Ex12_07.cpp
// Using the subscript operator
#include <iostream>
#include <memory>
#include <cstdlib>			               // For random number generator
#include <ctime>			                 // For time function
#include "Truckload.h"

// Function to generate integral random box dimensions from 1 to max_size
inline double random(double max_size)
{
  return 1 + static_cast<int>(max_size* static_cast<double>(std::rand()) / (RAND_MAX + 1.0));
}

int main()
{
  const double dimLimit {99.0}; 	     // Upper limit on Box dimensions
  std::srand((unsigned) std::time(0));  // Initialize the random number generator
  Truckload load;
  const size_t boxCount {20}; 	       // Number of Box object to be created

  // Create 20 Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

  std::cout << "The boxes are:\n";
  std::cout << load;

  // Find the largest Box in the  list
  double maxVolume {};
  size_t maxIndex {};
  size_t i {};
  while (load[i] )
  {
    if (load[i]->volume() > maxVolume)
    {
      maxIndex = i;
      maxVolume = load[i]->volume();
    }
    ++i;
  }

  std::cout << "\nThe largest box is: ";
  std::cout << *load[maxIndex] << std::endl;

  load.deleteBox(load[maxIndex]);
  std::cout << "\nAfter deleting the largest box, the list contains:\n";
  std::cout << load;
}
