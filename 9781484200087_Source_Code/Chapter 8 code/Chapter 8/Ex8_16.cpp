// Ex8_16.cpp
// Exercising pointers to  functions
#include  <iostream>
long  sum(long a, long  b);                                     // Function  prototype
long  product(long a, long  b);                                 // Function  prototype

int main()
{
  long(*pDo_it)(long, long) {};                                  // Pointer  to  function

  pDo_it = product;
  std::cout << "3*5 = " << pDo_it(3, 5) << std::endl;            // Call  product  thru  a pointer

  pDo_it = sum;                                                  // Reassign pointer to  sum()
  std::cout << "3 * (4+5) + 6 = " 
            << pDo_it(product(3, pDo_it(4, 5)), 6) << std::endl; // Call  thru  a pointer twice
}

// Function  to  multiply two values
long product(long a, long b)
{
  return a*b;
}

// Function  to  add two values
long sum(long a, long b) 
{
  return a + b;
}
