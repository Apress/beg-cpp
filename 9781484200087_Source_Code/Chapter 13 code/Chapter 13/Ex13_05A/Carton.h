// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H
#include <string>                                // For the string class
#include "Box.h"                                 // For Box class definition
using std::string;

class Carton : public Box
{
protected:
  string material {"Cardboard"};
  double thickness {0.125};                 // Material thickness inches
  double density {0.2};                     // Material density in pounds/cubic inch

public:
  // Constructors
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

  Carton(double lv, double wv, double hv, string desc, double dense, double thick) : Carton {lv, wv, hv, desc}
  {
    density = dense;
    thickness = thick;
    std::cout << "Carton(double,double,double,string, double,double) called.\n";
  }

  // Copy constructor
  Carton(const Carton& carton) : Box {carton}, material {carton.material}
  {
    std::cout << "Carton copy constructor" << std::endl;
  }

  // Destructor
  ~Carton()
  {
    std::cout << "Carton destructor. Material = " << material << std::endl;
  }

  // "Get carton weight" function
  double getWeight() const
  {
    return 2.0*(length*width + width*height + height*length)*thickness*density;
  }
};
#endif
