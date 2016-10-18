// Exercise 9.2 A lambda expression accessing a variable in the outer scope by reference
// This uses a lambda expression to scale vector elements but you could pass a
// lambda expression to modify() to transform elements in other ways.
#include <iostream>
#include <iomanip>
#include <vector>

// Function to modify vector elements using a lambda expression, fun
template <typename F>
void modify(std::vector<double>& values, F fun)
{
  for (auto& value : values)
    fun(value);
}

int main()
{
  std::vector <double> numbers {1.5, 2.5, 4.5, 16.5, -4.5, 5.5, 6.5, 3.5, 23.5};
  std::cout << "Numbers are:\n";
  for (auto n : numbers)
    std::cout << std::setw(5) << n;
  std::cout << std::endl;
  double scale {2.0};
  modify(numbers, [&scale](double& v){ v *= scale; });
  std::cout << "Numbers scaled by " << scale <<" are:\n";
  for (auto n : numbers)
    std::cout << std::setw(5) << n;
  std::cout << std::endl;
}