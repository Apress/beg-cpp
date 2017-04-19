// Ex6_06.cpp
// Using smart pointers
#include <iostream>
#include <iomanip>
#include <memory>                                             // For smart pointers
#include <vector>                                             // For vector container
#include <locale>                                             // For toupper()
using std::vector;
using std::shared_ptr;

int main()
{
  vector <shared_ptr<vector<double>>> records;                 // Temperature records by days
  size_t day{ 1 };                                             // Day number
  char answer{};                                               // Response to prompt
  double t{};                                                  // A temperature

  while (true)                                                 // Collect temperatures by day
  { // Vector to store current day's temperatures created on the heap 
    auto pDay = std::make_shared<vector<double>>();   
    records.push_back(pDay);                                   // Save pointer in records vector
    std::cout << "Enter the temperatures for day " << day++
              << " separated by spaces. Enter 1000 to end:\n";
    while (true)
    { // Get temperatures for current day
      std::cin >> t;
      if (t == 1000.0) break;

      pDay->push_back(t);
    }
    std::cout << "Enter another day's temperatures (Y or N)? ";
    std::cin >> answer;
    if (toupper(answer) == 'N') break;
  }
  double total{};
  size_t count{};
  day = 1;
  std::cout << std::fixed << std::setprecision(2) << std::endl;
  for (auto record : records)
  {
    std::cout << "\nTemperatures for day " << day++ << ":\n";
    for (auto temp : *record)
    {
      total += temp;
      std::cout << std::setw(6) << temp;
      if (++count % 5 == 0) std::cout << std::endl;
    }
    std::cout << "\nAverage temperature: " << total / count << std::endl;
    total = 0.0;
    count = 0;
  }
}
