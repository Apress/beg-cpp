// Exercise 2.4 Calculating the height of a tree
#include <iostream> 
#include <iomanip>
#include <cmath>

int main()
{
  const double inches_per_foot {12.0};
  const double pi {3.14159265};
  const double pi_degrees {180.0};
  double d_feet {};
  double d_inches {};
  double angle {};
  double eye_height {};

  std::cout << "Enter the distance from the tree in feet and inches: ";
  std::cin >> d_feet >> d_inches;
  double distance {d_feet + d_inches / inches_per_foot};

  std::cout << "Enter the angle of the top of the tree in degrees: ";
  std::cin >> angle;
  angle *= pi/pi_degrees;                                              // Convert angle to radians

  std::cout << "Enter your eye height from the ground in inches: ";
  std::cin >> eye_height;
  eye_height /= inches_per_foot;                                       // Convert to feet
  double height {eye_height + distance*std::tan(angle)};               // Tree height in feet
  double height_feet {std::floor(height)};
  double height_inches {std::floor(inches_per_foot*(height - height_feet) + 0.5)};

  std::cout << "\nThe height of the tree is "
            << height_feet << " feet "
            << height_inches << " inches.\n" << std::endl;
}