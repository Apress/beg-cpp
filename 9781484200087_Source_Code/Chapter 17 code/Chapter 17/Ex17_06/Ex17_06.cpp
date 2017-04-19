// Ex17_06.cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include "Primes.h"

int main()
{
  Primes primes;
  std::cout << "3rd prime is " << primes[2] << std::endl;
  std::cout << "5th prime is " << primes[4] << std::endl;
  ulong prime {primes.prime_after(50)};
  std::cout << "Prime greater than 50 is " << prime << std::endl;
  std::cout << "Prime following " << prime << " is " << primes.next_prime(prime) << std::endl;
  std::cout << "Primes between 100 and 300 are:\n";
  std::vector<ulong> values;
  prime = primes.prime_after(100);
  while (prime < 300)
  {
    values.push_back(prime);
    prime = primes.next_prime(prime);
  }
  size_t count {};
  size_t perline {6};
  for (auto p : values)
  {
    std::cout << std::setw(12) << p;
    if (
      (++count % perline) == 0) std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "500th prime is " << primes[499] << std::endl;
}