// Primes.h
// A class to generate primes
#ifndef PRIMES_H
#define PRIMES_H
#include <fstream>
#include <string>

using std::string;
using ulong = unsigned long long;

class Primes
{
private:
  std::fstream primesfile;                                 // The file stream - input & output
  size_t nprimes {};                                       // Number in the file
  ulong lastprime {};                                      // Last  prime in the file

  bool file_exists(string file);                           // Returns true if a file exists
  bool isprime(ulong n);                                   // Returns true if n is prime

public:
  Primes(string filename = "D:\\Example_Data\\primes_cache.bin");
  ~Primes() { primesfile.close(); }
  ulong prime_after(ulong n);                              // Next prime after an integer
  ulong next_prime(ulong prime);                           // Next prime after a prime
  ulong operator[](size_t n);                              // nth prime (indexed from 0)
};
#endif