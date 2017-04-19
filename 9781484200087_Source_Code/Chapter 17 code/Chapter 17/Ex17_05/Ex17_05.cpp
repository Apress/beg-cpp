// Ex17_05.cpp
// Using function templates for numeric I/O
#include <cctype>                                // For character functions
#include <fstream>                               // For file streams
#include <iostream>                              // For standard streams
#include <iomanip>                               // For stream manipulators
#include <array>                                 // For array container template
#include <vector>                                // For vector container template
#include <string>                                // For string type
#include "Binary_Numeric_IO.h"                   // For numeric I/O function templates
using  std::ios;
using  std::string;
using ulong = unsigned long long;

void check_output_file(string filename);

int main()
try
{
  const size_t primes_count {20};
  ulong primes[primes_count];
  string primesfile {"D:\\Example_Data\\primes.txt"};
  std::ifstream in {primesfile};
  if (!in) throw ios::failure{primesfile + " not found in main()."};
  for (size_t i {}; i < primes_count; ++i)
  {
    in >> primes[i];
    if (in.eof()) throw std::runtime_error {string {"not enough primes in "} +primesfile};
  }
  in.close();

  // Write array to binary file
  string binaryfile {"D:\\Example_Data\\primes.bin"};
  check_output_file(binaryfile);
  std::ofstream out {binaryfile};
  write(out, primes, primes_count);
  out.close();
  std::cout << binaryfile << " written." << std::endl;

  // Read into array
  ulong primesback[primes_count];
  in.open(binaryfile, ios::binary | ios::in);
  if (!in) throw ios::failure {binaryfile + " not found in main() ."};
  read(in, primesback);
  in.close();
  size_t perline {6};
  std::cout << "Primes read into array:\n";
  for (size_t i {}; i < primes_count; ++i)
  {
    std::cout << std::setw(10) << primesback[i];
    if (!((i + 1) % perline)) std::cout << '\n';
  }
  std::cout << std::endl;

  // Read binary primes into vector container
  in.open(binaryfile, ios::binary|ios::in);
  if (!in) throw ios::failure {binaryfile + " not found in main() ."};
  std::vector<ulong> primes_vector;
  read(in, primes_vector);
  in.close();

  // Write vector container contents to binary file
  string vectorfile {"D:\\Example_Data\\primesvector.bin"};
  check_output_file(vectorfile);
  out.open(vectorfile, ios::binary | ios::out);
  write(out, primes_vector);
  out.close();
  std::cout << vectorfile << " written." << std::endl;

  // Read binary file into array container
  in.open(vectorfile, ios::binary | ios::in);
  if (!in) throw ios::failure {vectorfile + " not found in main()."};
  std::array<ulong, primes_count> primesarray;
  read(in, primesarray);
  in.close();

  // Write array container contents to binary file
  string arrayfile {"D:\\Example_Data\\primesarray.bin"};
  check_output_file(arrayfile);
  out.open(arrayfile, ios::binary | ios::out);
  write(out, primesarray);
  out.close();
  std::cout << arrayfile << " written." << std::endl;

  // Read array container contents from file and list
  size_t count {};
  in.open(arrayfile, ios::binary | ios::in);
  if (!in) throw ios::failure {arrayfile + " not found in main()."};
  read(in, count);
  ulong prime {};
  for (size_t i {}; i < count; ++i)
  {
    read(in, prime);
    std::cout << std::setw(10) << prime;
    if (!((i + 1) % perline)) std::cout << '\n';
  }
  std::cout << std::endl;
}
catch (std::exception& ex)
{
  std::cout << ex.what() << std::endl;
}

// Check for overwriting existing file
void check_output_file(string filename)
{
  std::ifstream in(filename);
  if (in)
  {
    std::cout << filename << " exists. Overwrite(Y or N)?: ";
    char reply {};
    std::cin >> reply;
    std::cin.ignore();                           // Remove EOF
    if (std::toupper(reply) != 'Y')
      std::exit(1);
  }
}