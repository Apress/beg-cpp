// Box.h
#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>
#include <algorithm>                        // For max() and min() functions

class  Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Constructors
  Box(double lv, double wv, double hv) :
    length {std::max(lv, wv)}, width {std::min(lv, wv)}, height {hv} {}
  Box() = default;

  Box(const Box& box)                                      // Copy constructor
    : length {box.length}, width {box.width}, height {box.height} {}

  double volume() const                                    // Function to calculate the volume
  {
    return length*width*height;
  }

  // Accessors
  double getLength() const { return length; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  bool operator<(const Box& aBox) const;                   // Less-than operator
  bool operator<(double aValue) const;                     // Compare Box volume < double value
  Box operator+(const Box& aBox) const;                    // Function to add two Box objects
  void listBox();                                          // Output the Box
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

// Operator function to add two Box objects
inline Box Box::operator+(const Box& aBox) const
{
  // New object has larger length and width, and sum of heights
  return Box {length > aBox.length ? length : aBox.length,
    width > aBox.width ? width : aBox.width,
    height + aBox.height};
}

// Output the Box
inline void Box::listBox()
{
  std::cout << " Box(" << std::setw(2) << length << ","
    << std::setw(2) << width << ","
    << std::setw(2) << height << ")";
}
#endif
