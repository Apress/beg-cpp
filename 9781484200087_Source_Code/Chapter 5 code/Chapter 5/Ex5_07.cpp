// Ex5_07.cpp
// Using a do-while loop to manage input
#include <iostream>
#include <locale>                                    // For tolower() function

int main()
{
  char reply{};                                      // Stores response to prompt for input
  int count{};                                       // Counts the number of input values
  double temperature{};                              // Stores an input value
  double average{};                                  // Stores the total and average
  do
  {
    std::cout << "Enter a temperature reading: ";     // Prompt for input
    std::cin >> temperature;                          // Read input value

    average += temperature;                           // Accumulate total of values
    ++count;                                          // Increment count

    std::cout << "Do you want to enter another? (y/n): ";
    std::cin >> reply;                                // Get response
  } while (tolower(reply) == 'y');
  std::cout << "The average temperature is " << average / count << std::endl;
}
