// Exercise 3.4 Packing and unpacking characters.

#include <iostream>
#include <iomanip>

int main()
{
  unsigned int packed {};
  unsigned char ch {};
  std::cout << std::left << std::setw(26) << "Enter a character: ";
  std::cin >> ch;
  packed |= ch;

  std::cout << std::setw(26) << "Enter a second character: ";
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << std::setw(26) << "Enter a third character: ";
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << std::setw(26) << "Enter a fourth character: ";
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << "The word containing 4 packed characters is " << std::right
    << std::hex << std::showbase << std::internal << std::setfill('0') << packed << std::endl;

  // Unpacking packed...
  unsigned int mask {0x000000FF};                // Keep low order byte
  ch = mask & packed;                            // Low order byte
  std::cout << std::setfill(' ') << std::setw(4) << ch;

  ch = mask & (packed >> 8);                     // 2nd byte
  std::cout << std::setw(4) << ch;
  ch = mask & (packed >> 16);
  std::cout << std::setw(4) << ch;
  ch = mask & (packed >> 24);                    // 4th byte
  std::cout << std::setw(4) << ch << std::endl;
}