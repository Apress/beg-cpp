// Exercise 8.4 An overloaded plus() function. 
#include <iostream>
#include <string>
using std::string;
int plus(int a, int b);
double plus(double x, double y);
string plus(string s1, string s2);

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

  /*
  int d {plus(3, 4.2);
  This won't compile because there is more than one overloaded plus() function for the arguments.
  The compiler will not choose so there must be a unique match with a function signature.

  */
}


// Adding integer values
inline int plus(int a, int b)
{
  return a + b;
}

// Adding floating-point values
inline double plus(double x, double y)
{
  return x + y;
}

// Adding strings
inline string plus(string s1, string s2)
{
  return s1 + s2;
}



