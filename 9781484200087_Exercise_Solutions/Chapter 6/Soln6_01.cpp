// Exercise 6.1 Storing even numbers in an array and accessing them using pointer notation
#include <iostream>
#include <iomanip>

int main()
{
  const size_t n {50};
  size_t evens[n];
  for (size_t i {}; i < n; ++i)
    evens[i] = 2 * (i + 1);

  const size_t perline {10};
  std::cout << "The numbers are:\n";
  for (size_t i {}; i < n; ++i)
  {
    std::cout << std::setw(5) << *(evens + i);
    if ((i + 1) % perline) continue;                    // Uses the loop counter to decide when a newline is required
    std::cout << std::endl;
  }

  std::cout << "\nIn reverse order the numbers are:\n";
  for (int i {n - 1}; i >= 0; --i)                     // This won't work with size_t for the loop counter
  {                                                    // because size_t cannot be negative
    std::cout << std::setw(5) << *(evens + i);
    if (i % perline) continue;
    std::cout << std::endl;
  }
}