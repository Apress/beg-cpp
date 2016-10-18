// Exercise 8.5 Generating Fibonacci numbers using two functions.
//Once you have updated the smaller of val1 and val2, it then becomes the larger!
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

long& smaller(long& m, long& n);
long& larger(long& m, long& n);


int main()
{
  int count {};
  cout << "How many values in the Fibonacci sequence would you like? ";
  std::cin >> count;

  long n1 {1L};  // First in sequence
  long n2 {1L};  // Second in sequence
  std::cout << std::endl << std::setw(15) << n1 << std::setw(15) << n2;

  for (size_t i {2}; i < count; ++i)
  {
    if (i % 5 == 0)
      std::cout << std::endl;
    smaller(n1, n2) = n1 + n2;
    std::cout << std::setw(15) << larger(n1, n2);
  }
  std::cout << std::endl;
}

// Returns the smaller of the two arguments as a reference
// This means this function can be used on the rhs of an assignment
long& smaller(long& m, long& n)
{
  return m < n ? m : n;
}

// Returns the larger of the two arguments as a reference
// This means this function can be used on the rhs of an assignment
long& larger(long& m, long& n)
{
  return m > n ? m : n;
}