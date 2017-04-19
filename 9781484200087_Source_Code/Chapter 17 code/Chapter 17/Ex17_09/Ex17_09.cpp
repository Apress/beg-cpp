// Ex17_09.cpp
// Writing & reading base and derived class objects
#include  <fstream>                                   // For file streams
#include  <iostream>                                  // For standard streams
#include  <string>                                    // For string type
#include  <vector>                                    // For vector container
#include  "Box.h"
#include  "Carton.h"
using  std::string;

int main()
try
{
  std::vector<Box> boxes {Box {1.0, 2.0, 3.0}, Box {2.0, 2.0, 3.0},
    Box {3.0, 2.0, 2.0}, Box {4.0, 2.0, 3.0}};
  std::vector<Carton> cartons {Carton {6.0, 7.0, 8.0, "plastic"}, Carton {5.0, 7.0, 9.0, "wood"},
    Carton {5.0, 6.0, 5.0}};
  
  const string filename {"D:\\Example_Data\\containers.txt"};
  std::ofstream out {filename};
  if (!out)
    throw std::ios::failure {string {"Failed to open output file "} +filename};

  for (auto& box : boxes)
    out << box;                                      // Write a Box object
  out.close();                                       // Close the output stream

  std::cout << boxes.size() << " Box objects written to " << filename << std::endl;

  std::ifstream in {filename};                        // Create a file input stream
  if (!in)                                            // Make sure it's valid
    throw std::ios::failure {string("Failed to open input file ") + filename};

  std::cout << "Reading Box objects from the file:\n";
  Box box;
  while (true)
  {
    in >> box;                                        // Read an object from the file
    if (!in) break;                                   // End if EOF
    std::cout << box;                                 // Output the object read
  }
  in.close();                                         // Close the input stream

  out.open(filename);                                 // Open the output file
  for (auto& carton : cartons)
    out << carton;                                    // Write a Carton object
  out.close();                                        // Close the output stream
  std::cout << cartons.size() << " Carton objects written to " << filename << std::endl;

  in.open(filename);
  std::cout << "Reading Carton objects from the file:\n";
  Carton carton;
  while (true)
  {
    in >> carton;                                     // Read a Carton object from the file
    if (!in) break;                                   // End if EOF
    std::cout << carton;                              // Output the object read
  }
  in.close();                                         // Close the input stream
}
catch (std::exception& ex)
{
  std::cout << typeid(ex).name() << ": " << ex.what() << std::endl;
}
