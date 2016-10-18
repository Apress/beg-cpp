// Exercise 8.7 Computing Ackerman's function. 

#include <iostream> 
#include <iomanip> 

// Using unsigned long long provides the maximum possible range of values
// but is woefully inadequate for significant values of m and n.
unsigned long long ack(unsigned long long m,  unsigned long long n);

int main()
{
  size_t m {};
  size_t n {};
  std::cout << "Computing values of Ackerman's function - Ack(m,n):" << std::endl;
  std::cout << "Enter the upper limit for m: ";
  std::cin >> m;
  std::cout << "Enter the upper limit for n: ";
  std::cin >> n;
  if (m>3 && n>0 || m>2 && n>9)
    std::cout << "You are an optimist!" << std::endl;

  // Create array dynamically to hold values
  unsigned long long** ack_values = new unsigned long long*[m + 1];  // Pointer to array of arrays of unsigned long long elements
  for (size_t i = {}; i <= m; ++i)
    ack_values[i] = new unsigned long long[n + 1];

  // Store values in the array
  for (size_t i = {}; i <= m; ++i)
    for (size_t j = {}; j <= n; ++j)
      ack_values[i][j] = ack(i, j);

  for (size_t i {}; i <= m; i++)
  {
    std::cout << std::endl;
    for (size_t j {}; j <= n; ++j)
      std::cout << std::setw(12) << ack_values[i][j];
  }
  std::cout << std::endl;

  for (size_t i {}; i < m + 1; ++i)
    delete[] ack_values[i];
  delete ack_values;
}

unsigned long long ack(unsigned long long m, unsigned long long n)
{
  if (m == 0ULL)
    return n + 1;
  if (n == 0ULL)
    return ack(m - 1, 1);
  return ack(m - 1, ack(m, n - 1));
}
