// Exercise 6.4 Using an array of pointers to arrays.
// This is essentially an exercise in allocating heap memory using new.
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
  const size_t n_arrays {3};           // Number of arrays
  const size_t dimension {6};          // Dimension of each array
  auto arrays = new int*[n_arrays];
  for (size_t i {}; i < n_arrays; ++i)
    arrays[i] = new int[dimension];

  size_t value {};
  for (size_t j {}; j < dimension; ++j)
  {
    value = j + 1;
    for (size_t i {}; i < n_arrays; ++i)
    {
      arrays[i][j] = std::pow(value, i + 1);
    }
  }

  std::cout << "The values in the arrays are:\n";
  for (size_t i {}; i < n_arrays; ++i)
  {
    for (size_t j {}; j < dimension; ++j)
    {
      std::cout << std::setw(5) << arrays[i][j];
    }
    std::cout << std::endl;
  }

  // Now free the memory...
  for (size_t i {}; i < n_arrays; ++i)
    delete[] arrays[i];                       // First the arrays...   

  delete[] arrays;                            // ...then the array of pointers.        
}