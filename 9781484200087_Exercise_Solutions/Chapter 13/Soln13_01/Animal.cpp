// Exercise 13.1 - Animal.cpp
// Implementations of the Animal class and classes derived from Animal

#include <string>
#include <iostream>
#include "Animal.h"
using std::string;

// Constructor
Animal::Animal(string aName, int wt) : name(aName), weight(wt) {}

// Identify the animal
void Animal::who() const
{
  std::cout << "My name is " << name << " and I weigh " << weight << "lbs." << std::endl;
}