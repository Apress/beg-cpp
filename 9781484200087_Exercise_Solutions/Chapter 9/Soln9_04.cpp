// Exercise 9.4 A recursive lambda expression
#include <iostream>
#include <functional>

int main()
{
  std::function<size_t(size_t)> reverseNumber {[&reverseNumber](size_t no) -> size_t
  {
    static size_t r {};
    if (0 == no)
      return r;
    else
      r = r * 10 + no % 10;
    return reverseNumber(no / 10);
  }};
  int nn {12345}, r {};
  std::cout << nn << "  " << reverseNumber(nn) << std::endl;
}
