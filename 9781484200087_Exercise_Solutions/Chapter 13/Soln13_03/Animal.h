// Exercise 13.3 - Animal.h
// Animal class and classes derived from Animal

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using std::string;

class Animal
{
private:
  string name;                         // Name of the animal
  int weight;                          // Weight of the animal
public:
  Animal(string aName, int wt);        // Constructor
  void who() const;                    // Display name and weight
};

class Lion: public Animal
{
public:
  Lion(string aName, int wt) : Animal(aName, wt) {}
  void who() const;                    // Public member to access protected base function
};

class Aardvark: public Animal
{
public:
  Aardvark(string aName, int wt) : Animal(aName, wt){}
  void who() const;                    // Public member to access protected base function
};

#endif