// Exercise 3.1 Output integer and its 1's complement in decimal and hexadecimal.

// This tests how well you remember the stream manipulators as well as bitwise ~.
// You also need to be creative with the manipulators.
// The setw() manipulator only applies to the next output value so you must use it preceding each output value. 
// std::internal causes the fill character, '0', to be used internal to the hexadecimal values. The field width has to be
// set appropriately to get the correct number of hex digits including the leading zeros.

#include <iostream>
#include <iomanip>

int main()
{
  unsigned int value {};
  std::cout << "Enter a positive integer: ";
  std::cin >> value;
  unsigned int inverted_value {~value};

  unsigned int hex_digits {2 * sizeof(unsigned int)};       // Hex digits in value
  unsigned int width {hex_digits + 2};                      // Add 2 for 0x prefix
  unsigned int column_width {2 * width};                      // Output column width

  // Output column headings
  std::cout << std::right << std::setw(column_width) << "value"
    << std::setw(column_width) << "~value"
    << std::setw(column_width) << "~value+1" << std::endl;

  // Output hexadecimal values
  std::cout << std::hex << std::showbase << std::internal << std::setfill('0')
    << "          " << std::setw(width) << value
    << "          " << std::setw(width) << inverted_value
    << "          " << std::setw(width) << inverted_value + 1 << std::endl;

  // Output decimal values
  std::cout << std::dec << std::setfill(' ')
    << std::setw(column_width) << value
    << std::setw(column_width) << inverted_value
    << std::setw(column_width) << inverted_value + 1 << std::endl;
}