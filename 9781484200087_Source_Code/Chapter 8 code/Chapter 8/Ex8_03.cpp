// Ex8_03.cpp
// Failing to modify the original value of a function argument
#include  <iostream>
#include  <iomanip>

double change_it(double value_to_be_changed);    // Function  prototype

int main()
{
  double it{ 5.0 };
  double result {change_it(it)};

  std::cout << "After  function execution, it = " << it
    << "\nResult returned is " << result << std::endl;
}

// Function that  attempts to modify an argument and return it
double change_it(double it)
{
  it += 10.0;                                    // This modifies the copy
  std::cout << "Within function, it = " << it << std::endl;
  return it;
}
