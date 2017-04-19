// Ex5_10.cpp
// Sorting an array in ascending sequence - using an indefinite while loop
#include <iostream>
#include <iomanip>

int main()
{
  const size_t size {1000};            // Array size
  double x[size]{};                    // Stores data to be sorted
  double temp{};                       // Temporary store for a value
  size_t count{};                      // Number of values in array

  while (true)
  {
    std::cout << "Enter a non-zero value, or 0 to end: ";
    std::cin >> temp;
    if (!temp)
      break;

    x[count++] = temp;
    if (count == size)
    {
      std::cout << "Sorry, I can only store " << size << " values.\n";
      break;
    }
  }
  std::cout << "Starting sort." << std::endl;
  bool swapped{ false };           // true when values are not in order
  while (true)
  {
    for (size_t i{}; i < count - 1; ++i)
    {
      if (x[i] > x[i + 1])
      { // Out of order so swap them
        temp = x[i];
        x[i] = x[i+1];
        x[i + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped)                   // If there were no swaps
      break;                        // ...they are in order...
    swapped = false;                // ...otherwise, go round again.
  }

  std::cout << "Your data in ascending sequence:\n" 
            << std::fixed << std::setprecision(1);
  const size_t perline{ 10 };       // Number output per line
  size_t n{};                       // Number on current line          
  for (size_t i{}; i < count; ++i)
  {
    std::cout << std::setw(8) << x[i];
    if (++n == perline)             // When perline have been written...
    {
      std::cout << std::endl;       // Start a new line and...
      n = 0;                        // ...reset count on this line
    }
  }
  std::cout << std::endl;
}
