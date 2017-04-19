// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H
#include <string>                                // For the string class
#include "Box.h"                                 // For Box class definition
using std::string;

class Carton : private Box
{
private:
  string material;

public:
  using Box::volume;                              // Inherit as public
  Carton(const string desc = "Cardboard") : material {desc}{}     // Constructor
};
#endif
