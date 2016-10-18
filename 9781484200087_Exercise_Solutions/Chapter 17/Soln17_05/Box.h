// Box.h
#ifndef BOX_H
#define BOX_H
#include <fstream>
#include <iomanip>
#include <string>

class Box
{
protected:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  static const Box nullBox;                                // Box equivalent of nullptr

public:
  // Constructors
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}

  Box() = default;                                          // Default constructor

  Box(const Box& box)                                       // Copy constructor
    : length {box.length}, width {box.width}, height {box.height} {}

  virtual double volume() const                             // Calculate the volume
  {  return length*width*height;  }

  // Comparison operators for equality and inequality
  bool operator==(const Box& box) const { return length == box.length && width == box.width && height == box.height; }
  bool operator!=(const Box& box) const { return !(*this == box); }

  // Stream extraction and insertion
  friend std::ostream& operator<<(std::ostream& out, const Box& box);
  friend std::istream& operator>>(std::istream& in, Box& box);
};
static const Box nullBox {0, 0, 0};

// Stream output
inline std::ostream& operator<<(std::ostream& out, const Box&  box)
{
  return out << std::setw(10) << box.length << ' '
             << std::setw(10) << box.width << ' '
             << std::setw(10) << box.height << '\n';
}

// Stream input
inline std::istream& operator>>(std::istream& in, Box& box)
{
  return in >> box.length >> box.width >> box.height;
}
#endif
