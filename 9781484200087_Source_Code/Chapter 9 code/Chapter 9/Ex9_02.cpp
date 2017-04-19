// Ex9_02.cpp
// Passing lambda expressions as function arguments
#include <iostream>
#include <vector>
#include <string>
using std::string;

// Function template accepting a lambda expression as an argument
template <typename F> 
std::vector<double>& change(std::vector<double>& vec, F fun)
{
  for (auto& x : vec)
    x = fun(x);

  return vec;
}

int main()
{
  auto cube = [](double value) -> double { return value*value*value; };
  auto average = [](const std::vector<double>& v) -> double 
                 {
                   double sum{};
                   for (auto x : v)
                     sum += x;
                   return sum / v.size();
                 };

  std::vector<double> data{1.5, 2.5, 3.5, 4.5, 5.5};
  std::cout << "Average of values in data is " << average(data) << std::endl;

  change(data, [](double x){ return (x + 1.0)*(x + 2.0); });           // Direct lambda argument
  std::cout << "Average of changed values in data is " << average(data) << std::endl;
  std::cout << "Average of cubes of values in data is " << average(change(data, cube)) << std::endl;
}
