// Ex14_05.cpp
// Virtual functions using smart pointers
#include  <iostream>
#include  <memory>                               // For smart pointers
#include  <vector>                               // For vector
#include  "Box.h"                                // For the  Box class
#include  "ToughPack.h"                          // For the  ToughPack  class
#include "Carton.h"                              // For the Carton class

int main()
{
  std::vector<std::shared_ptr<Box>> boxes;
  boxes.push_back(std::make_shared<Box>(20.0, 30.0, 40.0));
  boxes.push_back(std::make_shared<ToughPack>(20.0, 30.0, 40.0));
  boxes.push_back(std::make_shared<Carton>(20.0, 30.0, 40.0, "plastic"));
  for (auto& p : boxes)
    p->showVolume();
}
