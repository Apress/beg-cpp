// Exercise 14.1 Exercising Zoo and Animal classes
#include "Animals.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using  std::string;

// Function to generate a random integer 0 to count-1
int random(size_t count) 
{
  return static_cast<size_t>((count*static_cast<long>(rand()))/(RAND_MAX+1L));
}

int main() 
{
  std::srand((unsigned)std::time(0));       // Seed random number generator

  std::vector<string> dogNames { "Fido", "Rover"   , "Lassie" , "Lambikins",   "Poochy",
                                 "Spit", "Gnasher" , "Samuel" , "Wellington" , "Patch"   };
  std::vector<string> sheepNames { "Bozo", "Killer", "Tasty", "Woolly", "Chops",
                                  "Blackie", "Whitey", "Eric" , "Sean"  , "Shep"   };
  std::vector<string> cowNames { "Dolly", "Daisy", "Shakey", "Amy", "Dilly",
                                 "Dizzy", "Eleanor", "Zippy" , "Zappy", "Happy" };

  size_t minDogWt {1};                      // Minimum weight of a dog in pounds
  size_t maxDogWt {120};                    // Maximum weight of a dog in pounds
  size_t minSheepWt {80};                   // Minimum weight of a dog in pounds
  size_t maxSheepWt {150};                  // Maximum weight of a dog in pounds
  size_t minCowWt {800};                    // Minimum weight of a dog in pounds
  size_t maxCowWt {1500};                   // Maximum weight of a dog in pounds

  std::vector<PAnimal> animals;             // Stores smart pointers to animals
  size_t nAnimals {};                       // Number of animals to be created
  std::cout << "How many animals in the zoo? ";
  std::cin >> nAnimals;
  // Create random animals
  for (size_t i {}; i < nAnimals; ++i)
    switch(random(3)) 
    {
    case 0:                // Create a sheep
      animals.push_back(std::make_shared<Sheep>(sheepNames[random(sheepNames.size())], minSheepWt + random(maxSheepWt-minSheepWt+1)));
      break;
    case 1:                // Create a dog
      animals.push_back(std::make_shared<Dog>(dogNames[random(dogNames.size())], minDogWt+random(maxDogWt-minDogWt+1)));
      break;
    case 2:                // Create a cow
      animals.push_back(std::make_shared<Cow>(cowNames[random(cowNames.size())], minCowWt+random(maxCowWt-minCowWt+1)));
      break;
    default:
      std::cout << "\nInvalid animal type selection." << std::endl;
      break;
    }

  // Create a zoo containing the animals
  // You could also create an empty zoo and add animals one at a time
  Zoo theZoo(animals);
  theZoo.showAnimals();                             // Display the animals
}