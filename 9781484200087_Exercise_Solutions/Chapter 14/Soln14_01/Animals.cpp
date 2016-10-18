// Exercise 14.1 Animals.cpp
// Implementations of the Animal class and classes derived from Animal

#include "Animals.h"
#include <string>
#include <cstdlib>
#include <iostream>
using std::string;

// Constructor
Animal::Animal(string theName, size_t wt) : name(theName), weight(wt) {}

// Return string describing the animal
string Animal::who() const
{
  return string("My name is ") + name + ". My weight is " + std::to_string(weight) + " lbs.";
}

// Return string describing the sheep
string Sheep::who() const
{
  return string("I am a sheep. ") + Animal::who();   // Call base function for common data
}

// Make like a sheep
string Sheep::sound() const
{
  return string("Baaaa!!");
}

// Return string describing the dog
string Dog::who() const
{
  return string("I am a dog. ") + Animal::who();     // Call base function for common data
}

// Make like a dog
string Dog::sound() const
{
  return string("Woof woof!!");
}

// Return string describing the cow
string Cow::who() const
{
  return string("I am a cow. ") + Animal::who();     // Call base function for common data
}

// Make like a cow
string Cow::sound() const
{
  return string("Mooooo!!");
}

// Constructor from a vector of animals
Zoo::Zoo(std::vector<PAnimal>& new_animals) : animals {new_animals} {}

// Add an animal to the zoo
void Zoo::addAnimal(PAnimal animal)
{
  animals.push_back(animal);
}

// Output the animals and the sound they make
void Zoo::showAnimals()
{
  for(auto animal : animals)
    std::cout << animal->who() << ' ' << animal->sound() << std::endl;
}
