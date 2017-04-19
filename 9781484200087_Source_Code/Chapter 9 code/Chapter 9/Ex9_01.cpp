// Ex9_01.cpp
// Using lambda expressions
#include <iostream>
#include <vector>
#include <string>
using std::string;

int main()
{
  auto cube = [](double value) -> double { return value*value*value; };
  double x{2.5};
  std::cout << x << " cubed is " << cube(x) << std::endl;

  auto average = [](const std::vector<double>& v) -> double 
                 {
                   double sum{};
                   for (const auto& x : v)
                     sum += x;
                   return sum / v.size();
                 };
  std::vector<double> data{1.5, 2.5, 3.5, 4.5, 5.5};
  std::cout << "Average of value in data is " << average(data) << std::endl;

  auto reverse = [](string& s) {
                                 size_t start{}, end{s.length() - 1};
                                 char temp{};
                                 while (start < end)
                                 {
                                   temp = s[start];
                                   s[start++] = s[end];
                                   s[end--] = temp;
                                 }
                                };

  string original{"ma is as selfless as I am"};
  string copy{original};
  reverse(copy);
  std::cout << "\"" << original << "\" reversed is \"" << copy << "\"" << std::endl;
}
