// Exercise 17.3a Writing Time class 0bjects to a file.

#include "Time.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

using std::string;

int main()
{
  string fileName;
  std::cout << "Enter the name of the file you want to write, including the path: ";
  std::getline(std::cin, fileName);
  std::ofstream outFile {fileName};
  if(!outFile)
  {
    std::cerr << "Failed to open output file. Program terminated.\n";
    exit(1);
  }

  Time period;
  char ch {'n'};

  do
  {
    std::cout << "Enter a time as hours:minutes:seconds, and press Enter: ";
    std::cin >> period;
    outFile << period;
    std::cout << "Do you want to enter another?(y or n): ";
    std::cin >> ch;
  }while(std::toupper(ch)=='Y');

  outFile.close();

  std::cout << std::endl;
}