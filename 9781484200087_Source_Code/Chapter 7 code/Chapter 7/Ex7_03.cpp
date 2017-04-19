// Ex7_03.cpp
// Comparing strings
#include <iostream>                         // For stream I/O
#include <iomanip>                          // For stream manipulators
#include <string>                           // For the string type
#include <locale>                           // For character conversion
#include <vector>                           // For the vector container
using std::string;

int main()
{
  std::vector<string> names;                // Vector of names
  string input_name;                        // Stores a name
  char answer{};                           // Response to a prompt

  do
  {
    std::cout << "Enter  a name: ";
    std::cin >> input_name;                 // Read  a name and...
    names.push_back(input_name);            // ...add it to the vector

    std::cout << "Do you want to enter another name? (y/n): ";
    std::cin >> answer;
  } while (tolower(answer) == 'y');

  // Sort the names in ascending sequence
  string temp;
  bool sorted{ false };                     // true when names are sorted
  while (!sorted)
  {
    sorted = true;
    for (size_t i{ 1 }; i < names.size(); ++i)
    {
      if (names[i - 1] > names[i])
      { // Out of order - so swap names
        temp = names[i];
        names[i] = names[i - 1];
        names[i - 1] = temp;
        sorted = false;
      }
    }
  }

  // Find the length of the longest name
  size_t max_length{};
  for (auto& name : names)
    if (max_length < name.length()) max_length = name.length();

  // Output the sorted names 5 to a line
  std::cout << "In ascending sequence the names you entered are:\n";
  size_t field_width = max_length + 2;
  size_t count{};
  for (auto& name : names)
  {
    std::cout << std::setw(field_width) << name;
    if (!(++count % 5)) std::cout << std::endl;
  }
  std::cout << std::endl;
}
