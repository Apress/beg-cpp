// Class representing a teacher
/*
****************************************************************
*
* The Teacher Class inherits from the
* "Person" base Class.
*
****************************************************************
*/
#ifndef TEACHER_H
#define TEACHER_H

bool isFile(std::ios& in);                             // Returns true if stream is a file
bool notFile(std::ios& in);                            // Returns true if not a file stream

#include <string>
#include "Person.h"
using std::string;

class Teacher : public Person
{
protected:
  size_t years_experience;
  long salary;

public:
  Teacher() = default;
  std::istream& get(std::istream& in) override;
  std::ostream& put(std::ostream& out) override;
};

// Read a teacher record from a stream
inline std::istream& Teacher::get(std::istream& in)
{
  Person::get(in);
  if (isFile(in))                                                  // If it's a file...
  {
    in >> years_experience >> salary;                              // ...just read the data
  }
  else                                                             // ...otherwise - prompt for input
  {
    std::cout << "Enter  the number of years experience: ";
    in >> years_experience;
    std::cout << "Enter the salary(integral number of $: ";
    in >> salary;
  }
  return in;
}

// Write a teacher record to a stream
inline std::ostream& Teacher::put(std::ostream& out)
{
  Person::put(out);                                                // Write the base part
  if (isFile(out))                                                 // If we are writing a file...
  {
   out << years_experience << "\n" << salary << std::endl;         // ...just write tha data
  }
  else
  {
    out << "Experience: " << years_experience << " years\n" 
        << "Salary: $" << salary << std::endl;
  }
  return out;
}
#endif