// Encapsulate an address
/*
A US address consists of four parts: address(up to 3 lines), city, state, ZIP code(5 digits).
The ZIP code is verified to be 5 digits.
Input and output of an Address object is done using the >> and << operators.
Input from a stream that is not a file is prompted and the ZIP code is checked.
Input from a file stream is assumed to be correct.
*/
#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using std::string;

bool isInteger(string s);                                  // Returns true if s contains only digits

class Address
{
protected:
  string address;                                // Address - one or more lines
  size_t line_count {};                          // Number of lines in address

  string city;
  string state;
  string zip;

public:
  Address() = default;

  string get_address() const { return address; }
  string get_city() const { return city; }
  string get_state() const { return state; }
  string get_zip() const { return zip; }

  // Friend I/O functions
  friend std::istream& operator>>(std::istream& in, Address& name);
  friend std::ostream& operator<<(std::ostream& out, Address& name);
};

inline std::istream& operator>>(std::istream& in, Address& addr)
{
  // If it's not file input, we need prompts and validation of the data
  if (notFile(in))
  {
    std::cout << "The address is one or more address lines followed by city, state, and zip code.\n";
    std::cout << "Enter one or more address lines followed by an empty line:\n";

    in.ignore();
    string line;
    while (true)
    {
      std::getline(in, line);
      if (line.empty()) break;
      addr.address += line + "\n";
      ++addr.line_count;
    }
    std::cout << "Enter the city:\n";
    std::getline(in, addr.city);
    std::cout << "Enter the state:\n";
    std::getline(in, addr.state);

    std::cout << "Enter the ZIP code (5 digits):\n";
    while (true)
    {
      in >> addr.zip;
      if (addr.zip.length() != 5)
      {
        std::cout << "ZIP code must be five digits. Try again.\n";
        continue;
      }
      if (!isInteger(addr.zip))
      {
        std::cout << "ZIP code must be only numeric digits. Try again.\n";
        continue;
      }
      break;
    }
    return in;
  }

  // It is a file so no prompts for input and the data is assumed to be OK
  in >> addr.line_count;                                   // Number of address lines
  string line;
  in >> std::skipws;
  for (size_t i {}; i < addr.line_count; ++i)
  {
    getline(in, line);                                     // Read a line
    addr.address += line + "\n";                           // Append the line and newline to address
  }

  std::getline(in, addr.city);                             // Read the city
  std::getline(in, addr.state);                            // Read the state
  in >> addr.zip;                                          // Read the zip code
  return in;
}

// Output to a stream
inline std::ostream& operator<<(std::ostream& out, Address& addr)
{
  if (isFile(out))                                          // If it's  a file...
    out << addr.line_count << " ";                          // ...write the line count
  out << addr.address << addr.city << '\n' << addr.state << '\n' << addr.zip << std::endl;
  return out;
}

#endif