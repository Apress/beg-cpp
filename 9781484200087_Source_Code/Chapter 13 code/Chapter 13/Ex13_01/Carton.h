// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H
#include <string>                                // For the string class
#include "Box.h"                                 // For Box class definition
using std::string;

class Carton : public Box
{
private:
  string material;

public:
  Carton(const string desc = "Cardboard") : material {desc}{}     // Constructor
  //  double carton_volume() { return length*width*height; }        // Uncomment for an error!
};
#endif
