// 90 was not an arbitrary choice for the number  of Fibonacci numbers.
// Fibonacci number grow very rapidly.
// 90 is around the most that are possible with type unsigned long long.

#include <iostream>
#include <iomanip>
#include <array>
using std::setw;

int main()
{
  const size_t n {90};
  std::array<unsigned long long, n> fib;
  fib[0] = fib[1] = 1UL;
  for (size_t i {2}; i < n; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];

  std::cout << "The first " << n << " Fibonacci numbers are:\n";
  const size_t perline {5};
  size_t count {};
  for (auto number : fib)
  {
    std::cout << setw(22) << number;
    if (++count % perline == 0) std::cout << std::endl;
  }
}
