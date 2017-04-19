// Carton.h
#ifndef CARTON_H
#define  CARTON_H
#include  <string>
#include  "Box.h"
using  std::string;

class  Carton : public Box
{
private:
  string material;

public:
  // Constructor  explicitly calling the  base constructor
  Carton(double lv, double wv, double hv, string str = "material") : Box {lv, wv, hv}
  {
    material = str;
  }

  // Function  to  calculate the  volume of  a Carton object
  double volume(int i = 50) const override
  {
    std::cout << "Carton parameter = " << i << std::endl;
    double vol {(length - 0.5)*(width - 0.5)*(height - 0.5)};
    return vol > 0.0 ? vol : 0.0;
  }
};
#endif
