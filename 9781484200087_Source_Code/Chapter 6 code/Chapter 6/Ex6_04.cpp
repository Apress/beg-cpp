// Ex6_04.cpp
// Calculating primes using pointer notation
#include  <iostream>
#include  <iomanip>

int main()  
{
  const size_t max{ 100 };                      // Number  of  primes required
  long primes[max]  { 2L, 3L, 5L };             // First three  primes defined
  size_t count{ 3 };                            // Count of  primes found so far
  long trial{ 5 };                              // Candidate prime
  bool isprime{ true };                         // Indicates when  a prime is found

  do
  {
    trial += 2;                                  // Next value  for  checking
    size_t i{};                                  // Index to  primes array

    // Try dividing the  candidate  by all the  primes we  have
    do
    {
      isprime = trial % *(primes + i) > 0;       // False for exact  division
    } while (++i < count && isprime);

    if (isprime)
    {                                            // We  got  one...
      *(primes + count++) = trial;               // ...so save it in primes array
    }
  } while (count < max);

  // Output primes 10 to  a line
  std::cout << "The first " << max << " primes are:" << std::endl;
  for (size_t i{}; i < max; ++i) 
  {
    std::cout << std::setw(7) << *(primes + i);
    if ((i+1) % 10 == 0)                         // Newline after every 10th  prime
      std::cout << std::endl;
  }
  std::cout << std::endl;
}
