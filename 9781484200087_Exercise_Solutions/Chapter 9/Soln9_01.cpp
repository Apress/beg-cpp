// Exercise 9.1 A lambda expression finding the largest even number in a vector
#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
  std::vector <int> numbers {1, 2, 4, 16, -4, 5, 6, 3,  23};
  std::cout << "Nunbers are:\n";
  for (auto n : numbers)
    std::cout << std::setw(5) << n;
  std::cout << std::endl;
  auto largest_even = [](std::vector<int>& v){
                                                  int largest {};
                                                  bool found {false};
                                                  for (auto n : v) 
                                                    if (!found && n % 2 == 0)
                                                    {
                                                      largest = n;
                                                      found = true;
                                                    }
                                                    else
                                                    {
                                                      if (found && n % 2 == 0 && largest < n)
                                                        largest = n;
                                                    }
                                                  return largest; };

  std::cout << "Largest even number is " << largest_even(numbers) << std::endl;                     
}
