// Exercise 6.3 Storing  numbers in a vector
// The result is an approximate value for pi.
// We must dereference values to use it with the subscript operator
// because it is not a vector but a pointer to a vector.
#include <iostream>
#include <cmath>
#include <vector>

int main()
{
  size_t n {};
  std::cout << "Enter the number of vector elements: ";
  std::cin >> n;
  auto values = new std::vector<double>(n);
  // If you use size_t as the type for the loop counter, the expression (i+1)*(i+1)
  // will produce an incorrect result for large value of i because the result will exceed the macximum for the type.
  // The index for the vector has to be size_t, and the explicit cast avoids a warning from the compiler.
  for (unsigned long long i {}; i < n; ++i)
    (*values)[static_cast<size_t>(i)] = 1.0 / ((i + 1)*(i + 1));
  double sum {};
  for (auto value : *(values))
    sum += value;

  std::cout << "Result is " << std::sqrt(6.0*sum) << std::endl;
  delete values;                                              // It's not an array this time!
}