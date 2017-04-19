// Ex17_04.cpp
// Copying files
#include  <iostream>                                  // For standard  streams
#include  <cctype>                                    // For character functions
#include  <fstream>                                   // For file streams
#include  <string>                                    // For string type
#include  <stdexcept>                                 // For standard exceptions
using  std::string;
using  std::ios;

void validate_files(string source, string target);    // Validate the files
int  main(int argc, char*  argv[]) 
try
{
  // Verify correct number  of  arguments
  if (argc != 3)
    throw std::invalid_argument {"Input and output file names required.\n"};

  // Check  for output file identical to input file
  const string source {argv[1]};                      // The input file
  const string target {argv[2]};                      // The destination for the copy
  if (source == target)
    throw std::invalid_argument {string("Cannot copy ") + source + " to itself.\n"};
  validate_files(source, target);

  // Create file streams
  std::ifstream in {source, ios::in | ios::binary};
  std::ofstream out(target, ios::out | ios::binary | ios::trunc);

  // Copy  the  file
  char ch {};
  while (in.get(ch))
    out.put(ch);

  if (in.eof())
    std::cout << source << " copied to  " << target << " successfully." << std::endl;
  else
    std::cout << "Error copying file" << std::endl;
}
catch (std::exception& ex)
{
  std::cout << std::endl << typeid(ex).name() << ": " << ex.what();
  return 1;
}

// Verify input file exists and check output file for overwriting
void validate_files(string infile, string outfile)
{
  std::ifstream in {infile, ios::in | ios::binary};
  if (!in)                                            // Stream object
    throw ios::failure {string("Input file ") + infile + " not found"};

  // Check  if output file exists
  std::ifstream temp {outfile, ios::in | ios::binary};
  if (temp)
  { // If the  file stream object is ok then the output file exists
    temp.close();                                     // Close the stream
    std::cout << outfile << " exists, do you want to  overwrite it? (y or n): ";
    if (std::toupper(std::cin.get()) != 'Y')
    {
      std::cout << "Destination file contents to be kept. Terminating..." << std::endl;
    }
  }
}