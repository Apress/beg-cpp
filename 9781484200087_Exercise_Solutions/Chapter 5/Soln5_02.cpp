// Exercise 5.2 Summing integers and calculating the average
#include <iostream>
#include <iomanip>
#include <cctype>

int main()
{
  char ch {};
  int n {};
  int count {};
  long total {};
  std::cout << "Enter the the first integer: ";
  while (true)
  {
    std::cin >> n;
    total += n;
    ++count;
    std::cout << "Do you want to enter another(y/n)?";
    std::cin >> ch;
    if (std::tolower(ch) == 'n')
      break;
    else
      std::cout << "Enter an integer: ";
  }
  std::cout << "The total is " << total << std::endl
    << "The average is " << std::setw(10) << std::setprecision(2)
    << std::fixed << (static_cast<double>(total) / count) << std::endl;
}