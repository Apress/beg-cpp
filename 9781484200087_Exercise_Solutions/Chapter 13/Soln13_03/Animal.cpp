// Exercise 13.3 - Animal.cpp
// Implementations of the Animal class and classes derived from Animal

#include <string>
#include <iostream>
#include "Animal.h"
using std::string;

// Constructor
Animal::Animal(string aName, int wt): name(aName), weight(wt) {}

// Identify the animal
void Animal::who() const {
  std::cout << "My name is " << name << " and I weigh " << weight << "lbs." << std::endl;
}

// Identify the Lion
void Lion::who() const {
  std::cout << "I am a lion.\n";
  Animal::who();                       // Call base function
}

// Identify the Aardvark
void Aardvark::who() const {
  std::cout << "\nI am an aardvark.\n";
  Animal::who();                       // Call base function
}