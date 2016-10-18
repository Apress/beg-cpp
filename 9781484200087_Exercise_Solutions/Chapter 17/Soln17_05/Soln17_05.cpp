// Ex17_05.cpp
// Writing & reading a linked list of Box objects
#include <fstream>                                   // For file streams
#include <iostream>                                  // For standard streams
#include <vector>                                     // For vector
#include <string>                                     // For string type
#include "Box.h"
#include "LinkedList.h"
using std::string;

int main()
try
{
  std::vector<Box> box_vector {Box {1, 2, 3}, Box {2, 3, 4}, Box {3, 4, 5}, Box {5, 6, 7},
    Box {6, 7, 8}, Box {7, 8, 9}};
  LinkedList boxes;
  std::cout << "Box objects in the linked list are:\n";

  for (auto& box : box_vector)
  {
    std::cout << box;
    boxes.addTail(box);
  }

  string filename;
  std::cout << "Enter the name of the file you want to write, including the path: ";
  std::getline(std::cin, filename);
  std::ofstream out {filename};
  if (!out)
    throw std::ios::failure {string {"Failed to open output file "} + filename};

  out << boxes;                                       // Write the list to the file
  out.close();

  LinkedList copy_boxes;                              // An empty list
  std::ifstream in {filename};                        // Create a file input stream
  if (!in)                                            // Make sure it's valid
    throw std::ios::failure {string("Failed to open input file ") + filename};

  std::cout << "Reading linked list of Box objects from the file...\n";
  in >> copy_boxes;                                   // Read the list from the file
  in.close();                                         // Close the input stream

  std::cout << "\nBox objects in the linked list read from the file are:\n" << copy_boxes;
}
catch (std::exception& ex)
{
  std::cout << typeid(ex).name() << ": " << ex.what() << std::endl;
}
