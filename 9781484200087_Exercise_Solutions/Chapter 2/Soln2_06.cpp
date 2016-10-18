// Exercise 2.6 Calculating the Body Mass Index.
// In the expression for bmi, h_inches will be implicitly converted to double
// because the divisor is type double.

// If you omit the std::fixed from the final output statement
// setprecision() specifies the number of digits precision. With std::fixed in effect
// it specifies the number of digits folllowing the decimal point.

#include <iostream>                                   // For standard streams
#include <iomanip>                                    // For stream manipulators

int main()
{
  const double lbs_per_kg {2.2};
  const double inches_per_foot {12.0};
  const double meters_per_foot {0.3048};
  double w_lbs {};
  unsigned int h_feet {};
  unsigned int h_inches {};

  std::cout << "Enter your weight in pounds: ";
  std::cin >> w_lbs;
  std::cout << "Enter you height in feet and inches: ";
  std::cin >> h_feet >> h_inches;

  double w_kg {w_lbs/lbs_per_kg};
  double h_meters {};
  h_meters = meters_per_foot*(static_cast<double>(h_feet) + h_inches/inches_per_foot);
  double bmi {w_kg / (h_meters*h_meters)};
  std::cout << "Your BMI is " << std::fixed << std::setprecision(1) << bmi << std::endl;
}