// Ex9_04.cpp
// Using lambda expressions in function templates
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <cmath>                       // For pow()
using std::vector;

// Template function to set a vector to values determined by a lambda expression
template <typename T> void setValues(vector<T>& vec, std::function<void(T&)> fun)
{
  for (size_t i{}; i < vec.size(); ++i)
    fun(vec[i]);
}

// Template function to list the values in a vector
template<class T> void listVector(const vector<T>& vec)
{
  int count{};                             // Counts number of outputs
  const int valuesPerLine{5};
  auto print = [&count, valuesPerLine](T value){
                                                std::cout << std::setw(10) << value << "  ";
                                                if (++count % valuesPerLine == 0) std::cout << std::endl; };
  for (size_t i{}; i < vec.size(); ++i)
    print(vec[i]);
}

int main()
{
  // Populate vector with values 1+1=2, 2+2=4, 4+3=7, 7+4=11, ...
  vector<int> integerData(50);
  int current{1};
  int increment{1};
  setValues<int>(integerData, [increment, &current](int& v) mutable{  v = current + increment++; 
                                                                      current = v; });
  std::cout << "Integer vector contains :" << std::endl;
  listVector(integerData);

  // Populate vector with x to nth power, x = 2.5 
  vector<double> values(10);
  size_t power{};
  double x{2.5};
  setValues<double>(values, [power, x](double& v) mutable{  v = std::pow(x, power++); });
  std::cout << "\nDouble vector contains:" << std::endl;
  listVector(values);
}
