// Exercise 14.2  Creating length objects

#include "Lengths.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>
using std::string;

// Read a length from the keyboard
std::shared_ptr<BaseLength> readLength()
{
  double value {};                                 // Stores the length value
  string units;                                    // Stores the units 

  for(;;)
  {
    std::cout << "\nEnter a length: ";
    std::cin >> std::skipws >> value;              // Skip whitespace and read the value
    if (!value) return nullptr;

    getline(std::cin, units);                      // Rest of line is units
    size_t index {units.find_first_not_of(" ")};   // Find first non-blank in units

    // Return the object type corresponding to the units
    switch(toupper(units[index])) 
    {
      case 'M':
        return std::make_shared<Meters>(value);
      case 'I':
        return std::make_shared<Inches>(value);
      case 'Y':
        return std::make_shared<Yards>(value);;
      case 'P':
        return std::make_shared<Perches>(value);
      default:
      std::cout << "\nInvalid units. Re-enter length: ";
      break;
    }
  }
}

int main()
{
  std::vector<std::shared_ptr<BaseLength> > pLengths;
  std::cout << "\nYou can enter lengths in inches, meters, yards, or perches."
    << "\nThe first character following the number specifies the units."
    << "\nThis can be i, m, y, or p, for inches, meters, yards, or perches."
    << "\ne.g. '22 ins' is 22 inches, '3.5 p' or '3.5perches' is 3.5 perches, '1y' is 1 yard."
    << std::endl
    << "\nPlease enter a length followed by the units or 0 to end:";

  while (true)
  {
    auto p = readLength();
    if (!p)break;

    pLengths.push_back(p);

  }

  // Output the lengths - we must figure out what type they are to display the units
  for(auto p : pLengths) 
  {
    string units(" invalid type");
    if(typeid(*p)==typeid(Inches))
      units = " inches";
    else if(typeid(*p)==typeid(Meters))
      units = " meters";
    else if(typeid(*p)==typeid(Yards))
      units = " yards";
    else if(typeid(*p)==typeid(Perches))
      units = " perches";
    std::cout << "\nLength is " << std::fixed << std::setprecision(2) << p->length() << units
              << " which is "   << static_cast<long>(p->BaseLength::length()) << " millimeters." << std::endl;
  }
}