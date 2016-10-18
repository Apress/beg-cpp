// Exercise 8.6 A plus() function template. 
// You can define a template specialization to allow plus() to be used with C-style strings.
// Note that you could not define a template specialization if the template parameters were not const.
// The type of a string literal is const char*.
// In that case you could define the overloaded function that is commented out below.
#include <iostream>
#include <string>
using std::string;

template <typename T>
T plus(const T a, const T b)
{
  return a + b;
}

template <>
const char* plus(const char* a, const char* b)
{
  return (string {a} + b).c_str();
}

/*
This function definition could oveload the template to allow plus() to be called for C-style strings
const char* plus(const char* a, const char* b)
{
  return (string {a} +b).c_str();
}
*/


int main()
{
  int n {plus(3, 4)};
  std::cout << "plus(3, 4) returns " << n << std::endl;
  double d {plus(3.2, 4.2)};
  std::cout << "plus(3.2, 4.2) returns " << d << std::endl;
  string s {plus("he", "llo")};
  std::cout << "plus(\"he\", \"llo\") returns " << s << std::endl;
  string s1 {"aaa"};
  string s2 {"bbb"};
  string s3 {plus(s1, s2)};
  std::cout << "With s1 as " << s1 << " and s2 as " << s2 << std::endl;

  std::cout << "plus(s1, s2) returns " << s3 << std::endl;
}



