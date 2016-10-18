// Exercise 14.4  Constructors for converting length objects

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

  // Output the lengths
  // These conversion can only use the conversion operators, because they are polymorphic
  //  (because a pLengths element is a smart pointer to the base class type and points to a derived class object).
  for (auto p : pLengths)
  {
    std::cout << "\nLength is " << static_cast<Inches>(*p).length() << std::fixed << std::setprecision(2) << " inches, "
      << static_cast<Yards>(*p).length() << " yards, "
      << static_cast<Meters>(*p).length() << " meters, "
      << static_cast<Perches>(*p).length() << " perches, "
      << static_cast<long>(p->BaseLength::length()) << " millimeters." << std::endl;
  }

  // Objects to exercise constructors to do conversions
  Inches inLength {5};
  Yards ydLength {5};
  Meters mLength {5};
  Perches pchLength {5};

  // The following use the class constructors to do conversions. You can verify this
  // by uncommenting  the output statement to each constructor.
  // However, if you comment out the conversion constructors for any of the classes,
  // it should still work using the inherited conversion operators instead.
  std::cout << "\nLength is " << inLength.length() << " inches, "
    << static_cast<Yards>(inLength).length() << " yards, "
    << static_cast<Meters>(inLength).length() << " meters, "
    << static_cast<Perches>(inLength).length() << " perches.\n";

  std::cout << "Length is " << static_cast<Inches>(ydLength).length() << " inches, "
    << ydLength.length() << " yards, "
    << static_cast<Meters>(ydLength).length() << " meters, "
    << static_cast<Perches>(ydLength).length() << " perches,\n";

  std::cout << "Length is " << static_cast<Inches>(mLength).length() << " inches, "
    << static_cast<Yards>(mLength).length() << " yards, "
    << mLength.length() << " meters, "
    << static_cast<Perches>(mLength).length() << " perches.\n";

  std::cout << "Length is " << static_cast<Inches>(pchLength).length() << " inches, "
    << static_cast<Yards>(pchLength).length() << " yards, "
    << static_cast<Meters>(pchLength).length() << " meters, "
    << pchLength.length() << " perches. " << std::endl;
}