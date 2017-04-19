// Ex17_02.cpp
// Reading the  primes file 
#include  <fstream>
#include  <iostream>
#include  <iomanip>
#include <string>
using ulong = unsigned long long;

int main()
{
  std::string  filename {"D:\\Example_Data\\primes.txt"};   // Input file name
  std::ifstream inFile {filename};                          // Create input stream object

  // Make  sure the  file stream is good
  if (!inFile)
  {
    std::cout << "Failed to open file " << filename << std::endl;
    return 1;
  }

  ulong  aprime {};
  size_t count {};
  size_t perline {6};
  while (true)                                              // Continue until EOF is found
  {
    inFile >> aprime;                                       // Read a value from the file
    if (inFile.eof()) break;                                // Break if EOF reached

    std::cout << (count++ % perline == 0 ? "\n" : "") << std::setw(10) << aprime;
  }
  std::cout << "\n" << count << " primes read from " << filename << std::endl;
}
