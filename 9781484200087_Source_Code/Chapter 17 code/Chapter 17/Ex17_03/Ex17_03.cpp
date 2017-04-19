// Ex17_03.cpp
// Reading and writing the primes file
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using std::ios;
using std::string;
using ulong = unsigned long long;

ulong nextprime(ulong aprime, const string filename);  // Find the prime following aprime

int main()
{
  string filename {"D:\\Example_Data\\more_primes.txt"};
  size_t nprimes {};                             // Number of primes required
  size_t count {};                               // Count of primes found
  ulong lastprime {};                            // Last prime found
  size_t perline {5};                            // Number output per line

  // Get number  of  primes required
  std::cout << "How  many  primes would you like (at least 4)?: ";
  std::cin >> nprimes;
  if (nprimes < 4) nprimes = 4;

  std::ifstream inFile;                          // Create input  file stream
  inFile.open(filename);                         // Open the filename file for input 
  std::ifstream::pos_type here {inFile.tellg()};
  if (!inFile.fail())                            // If there is a file...
  {                                              // ...read primes from it                          
    while (true)
    {
      inFile >> lastprime;
      if (inFile.eof()) break;

      std::cout << std::setw(10) << lastprime << (++count % perline == 0 ? "\n" : "");
      if (count == nprimes)
      {
        inFile.close();                          // We are done with the file
        std::cout << std::endl << count << "primes found in file." << std::endl;
        return 0;
      }
    }
  }

  // If we get to here, we need to find more primes
  inFile.clear();                                // Clear EOF flag
  inFile.close();                                // Reading is finished
  try
  {
    size_t oldCount {count};                     // The number that were in the file
    std::ofstream outFile;                       // Create an output stream object
    if (oldCount == 0)                           
    { // The file is empty
      outFile.open(filename);                    // Open file to create it
      if (!outFile.is_open())
        throw ios::failure {string {"Error opening output  file "} + filename + " in main()"};
      outFile << "2\n3\n5\n";   // Write 1st three primes to file
      outFile.close();
      std::cout << std::setw(10) << 2 << std::setw(10) << 3 << std::setw(10) << 5;
      lastprime = 5ULL;
      count = 3;
    }

    while (count < nprimes)
    {
      lastprime = nextprime(lastprime, filename);
      outFile.open(filename, ios::out | ios::app); // Open  file to  append  data
      if (!outFile.is_open())
        throw ios::failure {string {"Error opening output file "} + filename + " in main()"};
      outFile << lastprime << '\n';
      outFile.close();
      std::cout << std::setw(10) << lastprime << (++count % perline == 0 ? "\n" : "");
    }
    std::cout << std::endl << nprimes << " primes found. "
              << nprimes-oldCount << " added to file." << std::endl;
  }
  catch (std::exception& ex)  
  {
    std::cout << typeid(ex).name() << ": " << ex.what() << std::endl;
    return 1;
  }
}

// Find the next prime after last
ulong nextprime(ulong  last, const string filename)
{
  bool isprime {false};                          // true when we have a prime
  ulong aprime {};                               // Stores a prime from the file
  std::ifstream inFile;                          // Local file input stream object

  // Find the  next  prime
  ulong limit {};
  while (true)
  {
    last += 2ULL;                                // Next value  for  checking
    limit = static_cast<ulong>(std::sqrt(last));

    // Try dividing the candidate by all the primes up to limit
    inFile.open(filename);                       // Open the primes file
    if (!inFile.is_open())
      throw ios::failure {string {"Error opening input file "} +filename + " in nextprime()"};

    do
    {
      inFile >> aprime;
    } while (aprime <= limit && !inFile.eof() && (isprime = last % aprime > 0));

    inFile.close();
    if (isprime)                                 // We  got  one...
      return last;                               // ...so return it
  }
}
