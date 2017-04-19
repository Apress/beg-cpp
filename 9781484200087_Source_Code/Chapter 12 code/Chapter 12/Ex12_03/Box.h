// Box.h
#ifndef BOX_H
#define BOX_H
#include <iostream>

class  Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Constructors
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}

  Box() {}                                                             // No-arg constructor

  Box(const Box& box)                                                  // Copy constructor
    : length {box.length}, width {box.width}, height {box.height} {}

  double volume() const                                                // Function to calculate the volume
  {
    return length*width*height;
  }

  // Accessors
  double getLength() const { return length; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  bool operator<(const Box& aBox) const;                               // Less-than operator
  bool operator<(double aValue) const;                                 // Compare Box volume < double value

  // Equality operator
  bool operator==(const Box& aBox) const
  {
    return volume() == aBox.volume();
  }

};

// Less-than comparison for Box objects
inline bool Box::operator<(const Box& aBox) const
{
  return volume() < aBox.volume();
}

// Compare the volume of a Box object with a constant
inline bool Box::operator<(double aValue) const 
{
  return volume() < aValue;
}

// Function comparing a constant with volume of a Box object
inline bool operator<(double aValue, const Box& aBox)
{
  return aValue < aBox.volume();
}

#endif
