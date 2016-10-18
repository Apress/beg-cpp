/*
****************************************************************
*
* The "Student" Class inherited from the
* "Person" base Class.
*
****************************************************************
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <string>
#include "Person.h"
using std::string;

class Student : public Person
{
protected:
  string student_ID;
  int grade {};

public:
  Student() = default;
  std::istream& get(std::istream& in) override;
  std::ostream& put(std::ostream& out) override;
};

// Read a student record from a stream
inline std::istream& Student::get(std::istream& in)
{
  Person::get(in);                                                 // Deal with the base part of the object
  if (isFile(in))                                                  // It we are reading a file...
  {                                                                // ...no prompting or checking is necessary.
    in >> student_ID >> grade;
  }
  else
  {                                                                // Not a file, so prompt for input
    while (true)
    {
      std::cout << "Enter the student ID (IDnnnn): ";
      in >> student_ID;
      if (student_ID.length() == 6 &&                              // Must be 6 character and...
          student_ID.substr(0,2) == "ID" &&                        // ...start with "ID" followed by...
          isInteger(student_ID.substr(2,4)))                       // ...four decimal digits
        break;
      std::cout << "Invalid grade format. Should be IDnnnn. Try again.\n";
    }
    while (true)
    {
      std::cout << "Enter the student's grade: ";
      in >> grade;
      if (grade >= 0 && grade <= 100) break;
      std::cout << "Grade is a percentile and must be from 0 to 100. Try again.\n";
    }
  }
  return in;
}

// Write a student record to a stream
inline std::ostream& Student::put(std::ostream& out)
{
  Person::put(out);                                                // Write the base part of the object
  if (isFile(out))                                                 // If we are writing a file...
  {
    out << student_ID << " \n" << grade << std::endl;              // ...just write the data
  }
  else
    out << "Student ID: "<< student_ID << "\n" 
        << "Grade: " << grade << std::endl;

  return out;
}

#endif
