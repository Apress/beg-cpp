// Box.h
#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>

class Box
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
  Box operator+(const Box& aBox) const;                                // Function to add two Box objects
  Box operator*(size_t n) const;                                       // Post-multiply an object by an integer

  friend std::ostream& operator<<(std::ostream& stream, const Box& box);
};

// Pre-multiply an object by an integer
inline Box operator*(size_t n, Box& box)
{
  return Box {box.getLength(), box.getWidth(), n*box.getHeight()};
}

// Post-multiply an object by an integer
inline Box Box::operator*(size_t n) const
{
  return Box {length, width, n*height};
}

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


inline std::ostream& operator<<(std::ostream& stream, const Box& box)
{
  stream << " Box(" << std::setw(2) << box.length << ","
    << std::setw(2) << box.width << ","
    << std::setw(2) << box.height << ")";
  return stream;
}

#endif
