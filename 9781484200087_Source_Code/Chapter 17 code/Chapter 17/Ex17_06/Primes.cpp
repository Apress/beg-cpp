#include <cmath>                                           // For sqrt() function
#include <iostream>                                   
#include <fstream>                                         // For file streams
#include <stdexcept>                                       // For standard exceptions
#include "Primes.h"
#include "Binary_Numeric_IO.h"
using std::ios;

// Constructor
Primes::Primes(string filename)
{
  if (!file_exists(filename))                              // If no file...
  {
    std::ofstream out {filename, ios::binary|ios::out};    // ...create it
    nprimes = 3;
    lastprime = 5ULL;
    write(out, nprimes);
    write(out, 2ULL);
    write(out, 3ULL);
    write(out, 5ULL);
    out.close();
    primesfile.open(filename, ios::binary | ios::in | ios::out);
  }
  else
  {
    primesfile.open(filename, ios::binary | ios::in | ios::out);
    read(primesfile, nprimes);
    primesfile.seekg(sizeof(nprimes) + (nprimes-1)*sizeof(ulong), primesfile.beg);
    read(primesfile, lastprime);
  }
}

// Check whether a file exists
bool Primes::file_exists(string file)
{
  std::ifstream stream {file};
  return static_cast<bool>(stream);
}

// Finds prime > n
ulong Primes::prime_after(ulong n) 
{
  ulong prime {};
  if (n < lastprime)
  {
    primesfile.seekg(sizeof(nprimes), primesfile.beg);
    while (prime < n) read(primesfile, prime);
  }
  else
  {
    while((prime = next_prime(lastprime)) < n);
  }
  return prime;
}

// Find the prime that follows the prime argument
ulong Primes::next_prime(ulong prime) 
{
  if (prime < lastprime)
  { // Next prime must be in the file
    primesfile.seekg(sizeof(nprimes), primesfile.beg);
    ulong current {};
    for (size_t i {}; i < nprimes; ++i)
    {
      read(primesfile, current);
      if (prime < current) return current;
    }
    throw std::logic_error {string {"next_prime() fail. File contents incorrect or "} + std::to_string(prime) + " not a prime"};
  }

  // The next prime is not in the file
  ulong trial {lastprime + 2ULL};
  do
  {

    while (!isprime(trial)) trial += 2ULL;
    lastprime = trial;
    primesfile.seekp(0, primesfile.end);
    write(primesfile, lastprime);
    ++nprimes;
    primesfile.seekp(0);
    write(primesfile, nprimes);
    trial += 2ULL;
  } while (lastprime <= prime);
  return lastprime;
}

// Check if n is prime - sqrt(n) must be < lastprime
bool Primes::isprime(ulong n)
{
  ulong root_n {static_cast<ulong>(std::sqrt(n))};
  ulong prime {};
  primesfile.seekg(sizeof(nprimes), primesfile.beg);

  while (primesfile)
  {
    read(primesfile, prime);
    if ((n % prime) == 0) return false;
    if (prime > root_n)   return true;
  }
  throw std::logic_error {string {"isprime() fail. Could not determine primeness of "} + std::to_string(n)};
}

// Subscript operator - indexes from zero
ulong Primes::operator[](size_t n)
{
  ulong prime {};
  if (n < nprimes)
  { // The nth prime is in the file
    primesfile.seekg(sizeof(nprimes) + (n*sizeof(ulong)), primesfile.beg);
    read(primesfile, prime);
    return prime; 
  }

  // If we get to here, the nth prime is not in the file
  while (nprimes < n + 1)
  {
    lastprime = next_prime(lastprime);
  }
  //We have found the nth prime
  return lastprime;
}

