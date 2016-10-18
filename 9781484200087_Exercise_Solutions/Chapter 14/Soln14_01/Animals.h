// Exercise 14.1 Animals.h 
// Animal classes and class defining a Zoo
#ifndef ANIMALS_H
#define ANIMALS_H
#include <string>
#include <memory>
#include <vector>
using std::string;
class Animal;                                              // Class name declaration
using PAnimal = std::shared_ptr<Animal>;                   // required to compile this alias

class Animal
{
private:
  string name;                                              // Name of the animal
  size_t weight {};                                         // Weight of the animal

public:
  Animal(string theName, size_t wt);                       // Constructor
  virtual string who() const;                              // Return string containing name and weight
  virtual string sound() const = 0;                        // Display sound of an animal

};

class Sheep: public Animal
{
public:
  Sheep(string theName, size_t wt) : Animal(theName, wt) {}
  string who() const override;                             // Return string containing name and weight
  string sound() const override;                           // Display sound of a sheep
};

class Dog: public Animal
{
public:
  Dog(string theName, size_t wt) : Animal(theName, wt) {}
  string who() const override;                             // Return string containing name and weight
  string sound() const override;                           // Display sound of a dog
};

class Cow : public Animal
{
public:
  Cow(string theName, size_t wt) : Animal(theName, wt) {}
  string who() const override;                             // Return string containing name and weight
  string sound() const override;                           // Return sound of a cow
};

// The Zoo class representing a collection of animals 
class Zoo
{
private:
  std::vector<PAnimal> animals;                            // Stores smart pointers to the animals

public:
  Zoo() = default;                                         // Default constructor for an empty zoo
  Zoo(std::vector<PAnimal>& new_animals);                  // Constructor from a vector of animals
  void addAnimal(PAnimal animal);                          // Add an animal to the zoo
  void showAnimals();                                      // Output the animals and the sound they make
};

#endif