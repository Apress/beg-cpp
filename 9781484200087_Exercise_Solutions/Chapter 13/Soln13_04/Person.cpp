// Exercise 13.4 Person.cpp 
// Person class implementation

#include "Person.h"
#include <iostream>
using std::string;

Person::Person(size_t theAge, string theName, char theGender) : age {theAge}, name {theName}, gender {theGender}
{
  // Instead of just initializing the members with the argument values, you could
  // validate the arguments by doing reasonableness checks. 
  // e.g. Age should be less than 130 say. gender should be 'm' or 'f'
  // To handle a failure sensibly we really need exceptions, but we don't get to those until chapter 15. 
}

// Display details of Person object
void Person::who() const 
{
  std::cout << "\nThis is " << name << " who is " << age << " years old." << std::endl;
}

// Display details of Employee object
void Employee::who() const
{
  std::cout << name << " is a " << (gender=='f'? "female": "male") << " employee aged " << age << "." << std::endl;
}

// Display details of Executive object
void Executive::who() const
{
  std::cout << name << " is a " << (gender == 'f' ? "female" : "male") << " executive." << std::endl;
}