// Encapsulates a phone number
/*
A US phone number has three parts: a 3 digit area code, a 3 digit exchange code and a 4 digit number.
The number of digits for the three parts are validated.
The area code and exchange codes are checked for a valid initial digit.
The exchange code is also checked to verify that the last two digits are not 11.
There are further restriction on digits that could be checked but are not included here.
Input and output is supported through the >> and << operators.
Input from a stream that is not a file is prompted and validated.
*/
#ifndef PHONE_H
#define PHONE_H
#include <cctype>                                // For isdigit()
#include <iostream>                              // For standard streams
#include <fstream>                               // For file streams
#include <string>                                // For string
using std::string;

class Phone
{
protected:
  // The members are strings to maintain the number of digits with a leading zero
  // Remember - an integer with a leading zero is octal!
  string area_code;                              // 3 digits between 200 and 999
  string exchange_code;                          // 3 digits between 200 and 999 but not '#11'
  string number;                                 // 4 digits 0 to 9999

public:
  Phone() = default;

  // Friend I/O functions
  friend std::istream& operator>>(std::istream& in, Phone& phone);
  friend std::ostream& operator<<(std::ostream& out, Phone& phone);
};

// Input a phome number from the keyboard
inline std::istream& operator>>(std::istream& in, Phone& phone)
{
  if (isFile(in))
  {
    in >> phone.area_code >> phone.exchange_code >> phone.number;
    return in;
  }

  // Input stream is not a file so we need to prompt and check
  // Get the area code
  while (true)
  {
    std::cout << "Enter 3-digit area code: ";
    in >> phone.area_code;
    if (phone.area_code[0] == '0' || phone.area_code[0] == '1' || phone.area_code.length() != 3 || !isInteger(phone.area_code))
    {
      std::cout << "A valid area code has 3 digits with the first digit from 2 to 9, try again.\n";
      continue;
    }
    else
      break;
  }

  // Get the exchange code
  while (true)
  {
    std::cout << "Enter 3-digit exchange code: ";
    in >> phone.exchange_code;
    if (phone.exchange_code[0] == '0' || phone.exchange_code[0] == '1' || !isInteger(phone.exchange_code))
      {
        std::cout << "A valid exchange code must be 3 digits with the first digit from 2 to 9, try again.\n";
        continue;
      }
      else if (phone.exchange_code[1] == '1' && phone.exchange_code[2] == '1')
      {
        std::cout << "Invalid exchange code - the last two digits must not be 11, try again.\n";
        continue;
      }
      else
        break;
  }

  // Get number
  while (true)
  {
      std::cout << "Enter the number: ";
      in >> phone.number;
      if (phone.number.length() != 4 || !isInteger(phone.number))
      {
        std::cout << "The number must be four digits. Try again.";
        continue;
      }
      bool numeric {true};
      for (auto ch : phone.number)
      {
        if (!std::isdigit(ch))
        {
          numeric = false;
          break;
        }
      }
      if (!numeric)
      {
        std::cout << "The number must be numeric. Try again.";
        continue;
      }
      break;
  }
  return in;
}


// Stream output for a phone number
inline std::ostream& operator<<(std::ostream& out, Phone& phone)
{
  out << phone.area_code << " " << phone.exchange_code << " " << phone.number << std::endl;
  return out;
}
#endif