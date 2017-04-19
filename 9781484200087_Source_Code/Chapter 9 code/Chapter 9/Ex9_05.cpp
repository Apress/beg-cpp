// Ex9_05.cpp
// Recursive calls in a lambda expression
#include <iostream>
#include <functional>                  // For function<>

int main()
{
  // A lambda expression that returns the HCF of its arguments
  std::function<long long(long long, long long)> hcf =
    [&hcf](long long i, long long j) mutable ->long long   {
                               if (i < j) return hcf(j, i);
                               long long remainder{i%j};
                               if (!remainder) return j;
                               return hcf(j, remainder);   };
  
  // A lambda expression that outputs the HCF of the arguments
  auto showHCF = [&hcf](long long a, long long b) {
    std::cout << "The highest common factor of " << a << " and " << b
              << " is " << hcf(a, b) << std::endl;
                                                  };
  long long a{}, b{};
  while (true)
  {
    std::cout << "\nEnter two integers to find their HCF, or 0 to end: ";
    std::cin >> a;
    if (!a) break;
    std::cin >> b;

    showHCF(a, b);
  }
}
