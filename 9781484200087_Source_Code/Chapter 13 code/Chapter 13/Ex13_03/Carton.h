// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H
#include <string>                                // For the string class
#include "Box.h"                                 // For Box class definition
using std::string;

class Carton : public Box
{
private:
  string material {"Cardboard"};

public:
  Carton(double lv, double wv, double hv, const string desc) : Box {lv, wv, hv}, material {desc}
  {
    std::cout << "Carton(double,double,double,string) called.\n";
  }  

  Carton(const string desc) : material {desc}
  {  std::cout << "Carton(string) called.\n";  } 
  Carton(double side, const string desc) : Box {side}, material {desc}
  {
    std::cout << "Carton(double,string) called.\n";
  }
  Carton()
  {
    std::cout << "Carton() called.\n";
  }

  // Copy constructor
  Carton(const Carton& carton) : /*Box {carton}, */ material {carton.material}  // Uncomment for correct operation
  {
    std::cout << "Carton copy constructor" << std::endl;
  }
};
#endif
