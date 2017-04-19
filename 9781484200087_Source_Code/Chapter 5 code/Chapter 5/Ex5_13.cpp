// Ex5_13.cpp
// Using array<T,N> to create Body Mass Index (BMI) table
// BMI = weight/(height*height)   
// weight in kilograms, height in meters

#include <iostream>
#include <iomanip>
#include <array>                                 // For array<T,N>
using std::cout;
using std::endl;
using std::setw;

int main()
{
  const unsigned int min_wt {100U};              // Minimum weight in table
  const unsigned int max_wt{250U};               // Maximum weight in table
  const unsigned int wt_step{10U};
  const size_t wt_count {1 + (max_wt - min_wt) / wt_step};

  const unsigned int min_ht {48U};               // Minimum height in table
  const unsigned int max_ht{84U};                // Maximum height in table
  const unsigned int ht_step{ 2U };
  const size_t ht_count { 1 + (max_ht - min_ht) / ht_step };

  const double lbs_per_kg{ 2.2 };
  const double ins_per_m{ 39.37 };
  std::array<unsigned int, wt_count> weight_lbs {};
  std::array<unsigned int, ht_count> height_ins {};

  // Create weights from 100lbs in steps of 10lbs
  for (size_t i{}, w{ min_wt }; i < wt_count; w += wt_step, ++i)
  {
    weight_lbs[i] = w;
  }
  // Create heights from 48 inches in steps of 2 inches
  size_t i{};
  for (unsigned int h{ min_ht }; h <= max_ht; h += ht_step)
  {
    height_ins.at(i++) = h;
  }

  // Output table headings
  cout << setw(7) << " |";
  for (auto w : weight_lbs)
    cout << setw(5) << w << "  |";
  cout << endl;

  // Output line below headings
  for (size_t i{1}; i < wt_count; ++i)
    cout << "---------";
  cout << endl;

  double bmi{};                                  // Stores BMI
  unsigned int feet{};                           // Whole feet foe output
  unsigned int inches{};                         // Whole inches for output
  const unsigned int inches_per_foot{ 12U };
  for (auto h : height_ins)
  {
    feet = h / inches_per_foot;
    inches = h % inches_per_foot;
    cout <<  setw(2) << feet << "'" << setw(2) << inches << "\"" << "|";
    cout << std::fixed << std::setprecision(1);
    for (auto w : weight_lbs)
    {
      bmi = h / ins_per_m;
      bmi = (w / lbs_per_kg) / (bmi*bmi);
      cout << setw(2) << " " << bmi << " |";
    }
    cout << endl;
  }
  // Output line below table
  for (size_t i{ 1 }; i < wt_count; ++i)
    cout << "---------";
  cout << "\nBMI from 18.5 to 24.9 is normal" << endl;
}
