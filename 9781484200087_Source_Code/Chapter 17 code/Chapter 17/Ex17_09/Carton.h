// Carton.h
#ifndef CARTON_H
#define  CARTON_H
#include  <string>
#include  "Box.h"
using  std::string;

class Carton : public Box
{
private:
  string material;

public:
  // Constructor  explicitly calling the  base constructor
  Carton(double lv, double wv, double hv, string str = "cardboard") : Box {lv, wv, hv} 
  {
    material = str;  
  }

  Carton() = default;

  // Function  to  calculate the  volume of a Carton object
  double volume() const override
  {
    double vol {(length - 0.5)*(width - 0.5)*(height - 0.5)};
    return vol > 0.0 ? vol : 0.0;
  }

  // Stream output 
  std::ostream&  put(std::ostream& out) const override  
  {
    out << std::left << std::setw(15) << material << ' ';  // Write the material
    return Box::put(out);                                  // Write the sub-object
  }

  // Stream input 
  std::istream& Carton::get(std::istream& in) override
  {
    in >> material;                                        // Read the string
    return Box::get(in);                                   // Read the sub-object
  }
};
#endif
