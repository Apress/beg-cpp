// Ex17_01.cpp
// Writing primes to a file
#include <cmath>                                 // For sqrt() function
#include <fstream>                               // For file streams
#include <iomanip>                               // For stream manipulators
#include <iostream>                              // For standard streams
#include <string>                                // For string type
#include <vector>                                // For vector container 
using ulong = unsigned long long;
int main()
{
  size_t max {};                                 // Number  of  primes required
  std::cout << "How many prime would you like (at least 4)? : ";
  std::cin >> max;
  if (max < 4) max = 4;

  std::vector<ulong> primes {2ULL, 3ULL, 5ULL}; // First three  primes defined
  ulong trial {5ULL};                           // Candidate prime
  bool isprime {false};                         // true when  a prime is found
  ulong limit {};                               // Maximum divisor

  while (primes.size() < max)
  {
    trial += 2;                                  // Next value  for  checking
    limit = static_cast<ulong>(std::sqrt(trial));
    for (auto prime : primes)
    {
      if (prime > limit) break;                  // Only check divisors < square root
      isprime = trial % prime > 0;               // false for exact division...
      if (!isprime) break;                       // ...if so it's not a prime
    }
    if (isprime)                                 // If we found one...
      primes.push_back(trial);                   // ...save it
  }

  std::string filename {"d:\\Example_Data\\primes.txt"};
  std::ofstream  outFile {filename};            // Define file stream object

  // Output primes to file 
  size_t perline {5};                           // Prime values per line
  size_t count {};
  for (auto prime : primes)
  {
    outFile << std::setw(10) << prime;
    if (++count % perline == 0)                 // New line after every perline primes
      outFile << std::endl;
  }
  outFile << std::endl;
  std::cout << max << " primes written to " << filename << std::endl;
}
