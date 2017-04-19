// Ex17_08.cpp
// Writing & reading Box objects in binary mode
#include  <fstream>                                   // For file streams
#include  <iostream>                                  // For standard streams
#include  <string>                                    // For string type
#include  <vector>                                    // For vector container
#include  "Box.h"
using  std::string;

int main()
try
{
  std::vector<Box> boxes {Box {1.0, 2.0, 3.0}, Box {2.0, 2.0, 3.0},
    Box {3.0, 2.0, 2.0}, Box {4.0, 2.0, 3.0},
    Box {1.0, 4.0, 3.0}, Box {2.0, 2.0, 4.0}};

  const string filename {"D:\\Example_Data\\boxes.bin"};
  std::ofstream out {filename, std::ios::binary};
  if (!out)
    throw std::ios::failure {string {"Failed to open output file "} + filename};

  for (auto& box : boxes)
    write(out, box);                                  // Write a Box object
  out.close();                                        // Close the output stream

  std::cout << boxes.size() << " Box objects written to " << filename << std::endl;

  std::ifstream in {filename, std::ios::binary};      // Create a file input stream
  if (!in)                                            // Make sure it's valid
    throw std::ios::failure {string("Failed to open input file ") + filename};

  std::cout << "Reading objects from the file.\n";
  std::vector<Box> newBoxes;
  Box newBox;
  while (true)
  {
    if(!read(in, newBox)) break;
    newBoxes.push_back(newBox);
  }
  in.close();                                         // Close the input stream
  std::cout << newBoxes.size() << " objects read from " << filename << ":\n";
  for (auto& box : newBoxes)
    std::cout << box;
}
catch (std::exception& ex)
{
  std::cout << typeid(ex).name() << ": " << ex.what() << std::endl;
}
