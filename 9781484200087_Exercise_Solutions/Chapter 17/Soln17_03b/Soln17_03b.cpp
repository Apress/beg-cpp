// Exercise 17.3b Reading Time class 0bjects from a file.

#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using std::string;

int main()
{
  string fileName;
  std::cout << "Enter the name of the file you want to read, including the path: ";
  std::getline(std::cin, fileName);
  std::ifstream inFile {fileName};
  if(!inFile)
  {
    std::cerr << "Failed to open input file. Program terminated.\n";
    exit(1);
  }

  Time period;
  size_t count {};
  const size_t perline {5};
  std::cout << "Times on file are:\n";

  while(!(inFile >> period).eof())
  {
    std::cout << period;
    if(!(++count % perline))
      std::cout << std::endl;              // Newline every 5th output
  }
  std::cout << std::endl;
  inFile.close();
}