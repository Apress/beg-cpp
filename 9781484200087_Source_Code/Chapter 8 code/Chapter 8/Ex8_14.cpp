// Ex8_14.cpp
// Using a function template
#include <iostream>

template<typename T> T larger(T a, T b);    // Function  template  prototype

int main()
{
  std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
  std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

  int a_int{35}, b_int{45};
  std::cout << "Larger of " << a_int << " and " << b_int << " is "
    << larger(a_int, b_int) << std::endl;

  long  a_long{9L}, b_long{8L};
  std::cout << "Larger of " << a_long << " and " << b_long << " is "
    << larger(a_long, b_long) << std::endl;
}

// Template for functions to return the larger of two values
template  <typename T>
T larger(T a, T b)
{
  return a>b ? a : b;
}
