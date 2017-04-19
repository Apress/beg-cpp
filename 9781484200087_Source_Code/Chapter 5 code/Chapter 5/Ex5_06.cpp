// Ex5_06.cpp
// Allocating an array at runtime
#include  <iostream>

int main()
{
  size_t count {};
  std::cout << "How many heights will you enter? ";
  std::cin >> count;
  unsigned int height[count];               // Create the array of count elements

  // Read the heights
  size_t entered {};
  while(entered < count)
  {
    std::cout <<"Enter a height: ";
    std::cin >> height[entered];
    if(height[entered])                     // Make sure value is positive
    {
      ++entered;
    }
    else
    {
      std::cout << "A height must be positive - try again.\n";
    }
  }

  // Calculate the sum of the heights
  unsigned int total {};
  for(size_t i {}; i<count; ++i)
  {
    total += height[i];
  }
  std::cout << "The average height is " << total/count << std::endl;
}

