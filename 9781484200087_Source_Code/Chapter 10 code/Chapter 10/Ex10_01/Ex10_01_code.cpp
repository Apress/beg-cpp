// Ex10_01_code.cpp
// Using a namespace
#include <iostream>
#include <string>

namespace data
{
  extern const double pi;              // Variable is defined in another file 
  extern const std::string days[];     // Array is defined in another file
}

int main()
{
  std::cout << "pi has the value " << data::pi << std::endl;
  std::cout << "The second day of the week is " << data::days[1] << std::endl;
}
