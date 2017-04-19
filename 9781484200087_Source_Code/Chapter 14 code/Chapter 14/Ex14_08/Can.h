// Can.h Class defining a cylindrical can of a given height and diameter
#ifndef CAN_H
#define  CAN_H
#include  "Vessel.h"

class  Can : public Vessel
{
protected:
  double diameter {1.0};
  double height {1.0};
  constexpr static double pi {3.14159265};

public:
  Can(double d, double h) : diameter {d}, height {h} {}

  double volume() const override { return pi*diameter*diameter*height/ 4.0; }
};
#endif
