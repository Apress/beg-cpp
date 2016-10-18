// Encapsulates a name
/*
A name consists of a first and a second name.
There are get() and set() functions for changing a name.
A name object can be read or written to a stream using >> and << operators.
If a name is read from a stream that is not a file, input is prompted.
*/
#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <string>
using std::string;

bool isFile(std::ios& in);                             // Returns true if stream is a file
bool notFile(std::ios& in);                            // Returns true if not a file stream

class Name
{
protected:
  string first_name;
  string second_name;

public:
  Name() = default;

  string get_first_name() const{ return first_name; }
  string get_second_name() const { return second_name; }
  void set_first_name(string name) { first_name = name; }
  void set_second_name(string name) { second_name = name; }

  // Compare names for equality
  bool operator==(Name& name)
  {
    return (first_name == name.first_name) && (second_name == name.second_name);
  }

  // Friend I/O functions
  friend std::istream& operator>>(std::istream& in, Name& name);
  friend std::ostream& operator<<(std::ostream& out, Name& name);
};

// Read a Name from a stream
inline std::istream& operator>>(std::istream& in, Name& name)
{
  if (notFile(in))                                                 // If it's not a file, then prompt for input
    std::cout << "Enter first and second names separated by one or more spaces: ";
  in >> name.first_name >> name.second_name;
  return in;
}

// Write a name to a stream
inline std::ostream& operator<<(std::ostream& out, Name& name)
{
  out << name.first_name << " " << name.second_name << std::endl;
  return out;
}
#endif