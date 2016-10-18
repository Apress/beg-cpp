// Exercise 13.4 Person.h
// Person class and classes derived from Person

#ifndef PERSON_H
#define PERSON_H
#include <string>
using std::string;

class Person
{
protected:
  size_t age {};                                       // Age in years
  string name;
  char gender {'f'};                                   // 'm' or 'f'
public:
  Person() = default;                                  // Default constructor
  Person(size_t theAge, string theName, char theGender);
  void who() const;                                    // Display details
};

class Employee : public Person
{
protected:
  long personnelNumber {};

public:
  Employee() = default;                          // Default constructor - necessary to define arrays
  Employee(size_t theAge, string theName, char theGender, long persNum) :
                                                 Person {theAge, theName, theGender}, personnelNumber {persNum} {}
  void who() const;                              // Display details

};

class Executive: public Employee
{
public:
  Executive() = default;                         // Default constructor - necessary to define arrays
  Executive(size_t theAge, string theName, char theGender, long persNum) :
                                                 Employee {theAge, theName, theGender, persNum} {}
  void who() const;                              // Display details
};

#endif