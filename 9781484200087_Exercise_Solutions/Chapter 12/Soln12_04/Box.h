// Box.h
#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>

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
  Box operator+(const Box& aBox) const;                                // Function to add two Box objects
  Box operator*(size_t n) const;                                       // Post-multiply an object by an integer
  size_t operator/(const Box& aBox) const;                             // Function to divide one Box object by another
  double operator%(const Box& aBox) const;                             // Volume left after dividing one Box object by another

  friend std::ostream& operator<<(std::ostream& stream, const Box& box);
};

// Volume left after dividing one Box object by another
// This is easy now we have the / operator
inline double Box::operator%(const Box& box) const
{
  size_t n {*this / box};
  return volume() - n*box.volume();
}

// Function to divide one Box object by another - box1/box2
// This assumes box2 boxes are in the same orientation when packed in box1
// although box2 can be in any aorientation with respect to box1.
// The result will be zero if any dimension of box1 is less than that of box2.
inline size_t Box::operator/(const Box& box) const
{
  // Lambda expression to calculate division for a given orientation of box
  auto trial = [this](double L, double W, double H){ return static_cast<size_t>(this->length / L)*
    static_cast<size_t>(this->width / W)*
    static_cast<size_t>(this->height / H); };

  size_t result {trial(box.length, box.width, box.height)};                    // box in LxWxH orientation
  if (!result) return 0;

  size_t temp {trial(box.length, box.height, box.width)};                      // box in LxHxW orientation
  if (temp > result)result = temp;

  temp = trial(box.width, box.height, box.length);                             // box in WxHxL orientation
  if (temp > result)result = temp;

  temp = trial(box.width, box.length, box.height);                             // box in WxLxH orientation
  if (temp > result)result = temp;

  temp = trial(box.height, box.length, box.width);                             // box in HxLxW orientation
  if (temp > result)result = temp;

  temp = trial(box.height, box.width, box.length);                             // box in HxWxL orientation
  if (temp > result)result = temp;
  return result;
}

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
