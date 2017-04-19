// Cube.h
#ifndef CUBE_H
#define CUBE_H
class  Cube
{
public:
  double side;

  Cube(double side);                      // Constructor
  double volume();                        // Calculate  volume of  a cube
  bool  compareVolume(Cube  aCube);       // Compare  volume of  a cube with  another
};
#endif
