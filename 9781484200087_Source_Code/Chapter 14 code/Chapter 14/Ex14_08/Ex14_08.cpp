// Ex14_08.cpp
// Using an indirect base class
#include  <iostream>
#include  <vector>                     // For the vector container
#include  "Box.h"                      // For the  Box class
#include  "ToughPack.h"                // For the  ToughPack  class
#include  "Carton.h"                   // For the  Carton class
#include  "Can.h"                      // for the  Can  class

int main()
{
  Box box {40, 30, 20};
  Can can {10, 3};
  Carton carton {40, 30, 20, "Plastic"};
  ToughPack hardcase {40, 30, 20};

  std::vector<Vessel*>  pVessels {&box, &can, &carton, &hardcase};

  for (auto p : pVessels)
    std::cout << "Volume is " << p->volume() << std::endl;
}
