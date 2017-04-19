// Ex14_09.cpp
// Using an indirect base class
#include  <iostream>
#include  <vector>                     // For the vector container
#include  "Box.h"                      // For the  Box class
#include  "ToughPack.h"                // For the  ToughPack  class
#include  "Carton.h"                   // For the  Carton class
#include  "Can.h"                      // for the  Can  class

int main()
{
  std::vector<Vessel*>  pVessels {new Box {40, 30, 20}, new Can {10, 3},
                                  new Carton {40, 30, 20, "Plastic"}, new ToughPack {40, 30, 20}};

  for (auto p : pVessels)
    std::cout << "Volume is " << p->volume() << std::endl;

  // Free the memory
  for (auto p : pVessels)
    delete p;
}
