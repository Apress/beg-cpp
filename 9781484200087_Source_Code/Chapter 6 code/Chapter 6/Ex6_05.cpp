// Ex6_05.cpp
// Calculating primes using dynamic memory allocation
#include  <iostream>
#include  <iomanip>
#include <cmath>                                             // For square root function

int main()
{
  size_t  max{};                                             // Number of primes required
  size_t count{ 3 };                                         // Count of primes found

  std::cout << "How many primes would you like? ";
  std::cin >> max;                                           // Read number required and...
  unsigned long long* primes{ new unsigned long long[max] }; // ...allocate memory for them

  *primes = 2uLL;                                            // Insert  three  seed primes...
  *(primes + 1) = 3uLL;
  *(primes + 2) = 5uLL;
  unsigned long long trial{ *(primes + 2) };                 // Candidate prime
  bool  isprime{ false };                                    // Indicates when a prime is found

  unsigned long long limit{};                                // Store square root of trial
  do
  {
    trial += 2;                                              // Next value  for  checking
    limit = static_cast<unsigned long long>(std::sqrt(trial));
    size_t i{};                                              // Index  to  primes array
    do
    {
      isprime = trial %  *(primes + i) > 0;                  // False  for exact  division
    } while (primes[++i] <= limit && isprime);

    if (isprime)                                             // We  got  one...
      *(primes + count++) = trial;                           // ...so save it in primes array
  } while (count < max);

  // Output primes 10 to  a line 
  for (size_t i{}; i < max; ++i)
  {
    std::cout << std::setw(10) << *(primes + i);
    if ((i + 1) % 10 == 0)                                    // After every  10th  prime...
      std::cout << std::endl;                                 // ...start a new line
  }
  std::cout << std::endl;
  delete[] primes;                                            // Free up memory...
  primes = nullptr;                                           // ... and reset the pointer
}
