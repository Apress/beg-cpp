// Ex8_11.cpp
// Using static variables
#include  <iostream>
#include  <iomanip>

long  next_Fibonacci();

int main()
{
  size_t count{};
  std::cout << "Enter the number of Fibonacci values to be generated: ";
  std::cin >> count;
  std::cout << "The Fibonacci  Series:\n";
  for (size_t i{}; i < count; ++i)
  {
    std::cout << std::setw(10) << next_Fibonacci();
    if (!((i + 1) % 8))                              // After every 8th output...
      std::cout << std::endl;                        // ...start a new  line
  }
  std::cout << std::endl;
}

// Generate the next number in the Fibonacci series
long  next_Fibonacci()
{
  static long  last;                            // Last number in sequence
  static long  last_but_one{1L};               // Last but one in sequence

  long  next{last + last_but_one};             // Next is sum of the last two
  last_but_one = last;                         // Update last but one
  last = next;                                  // Last is new one
  return last;                                  // Return the new value
}
