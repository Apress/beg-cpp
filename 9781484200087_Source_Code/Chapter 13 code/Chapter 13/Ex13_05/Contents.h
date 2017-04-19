// Contents.h - Dry contents
#ifndef CONTENTS_H
#define CONTENTS_H
#include <iostream>

class Contents
{
protected:
  string name {"cereal"};                   // Contents type
  double volume {};                         // Cubic inches
  double unitWeight {0.03};                 // Pounds per cubic inch

public:
  Contents(const string name, double wt, double vol) : name {name}, unitWeight {wt}, volume {vol} 
  { std::cout << "Contents(string,double,double) called.\n";  }

  Contents(const string name) : name {name} { std::cout << "Contents(string) called.\n";  }

  Contents()  { std::cout << "Contents() called.\n";  }

  // Destructor
  ~Contents()
  {
    std::cout << "Contents destructor" << std::endl;
  }

  // "Get contents weight" function
  double getWeight() const
  {
    return volume*unitWeight;
  }
};
#endif
