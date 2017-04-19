// Ex17_07.cpp
// Writing Box objects to  a file and reading them back
#include  <fstream>
#include  <iostream>
#include  <string>
#include  <vector>
#include  "Box.h"
using  std::string;

int main()
try
{
  std::vector<Box> boxes {Box {1.0, 2.0, 3.0}, Box {2.0, 2.0, 3.0},
    Box {3.0, 2.0, 2.0}, Box {4.0, 2.0, 3.0},
    Box {1.0, 4.0, 3.0}, Box {2.0, 2.0, 4.0}};

  const string filename {"D:\\Example_Data\\boxes.txt"};
  std::ofstream out {filename};
  if (!out)
    throw std::ios::failure {string {"Failed to open output file "} +filename};

  for (auto& box : boxes)
    out << box;                        // Write a Box object
  out.close();                         // Close the input stream

  std::cout << boxes.size() << " Box objects written to the file." << std::endl;

  std::ifstream in {filename};         // Create a file input stream
  if (!in)                              // Make sure it's valid
    throw std::ios::failure {string("Failed to open input file ") + filename};

  std::cout << "Reading objects from the file.\n";
  std::vector<Box> newBoxes;
  Box newBox;
  while (true)
  {
    in >> newBox;
    if (!in) break;
    newBoxes.push_back(newBox);
  }
  in.close();                          // Close the input stream
  std::cout << newBoxes.size() << " objects read from the file:\n";
  for (auto& box : newBoxes)
  std::cout << box;
}
catch (std::exception& ex)
{
  std::cout << typeid(ex).name() << ": " << ex.what() << std::endl;
}
