// Box.h
#ifndef BOX_H
#define BOX_H
#include <fstream>
#include <iomanip>

class Box
{
protected:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Constructors
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}

  Box() = default;                                          // Default constructor

  Box(const Box& box)                                       // Copy constructor
    : length {box.length}, width {box.width}, height {box.height} {}

  virtual double volume() const                             // Calculate the volume
  {   return length*width*height; }

  // Member  stream I/O  functions
  virtual std::ostream& put(std::ostream& out) const        // Stream output
  {
    return out << std::setw(10) << length << ' ' << std::setw(10) << width << ' '
      << std::setw(10) << height << '\n';
  }

  virtual std::istream& get(std::istream& in)                // Stream input
  {
    return in >> length >> width >> height;
  }
};

inline std::ostream& operator<<(std::ostream& out, const  Box&  box)
{
  return box.put(out);
}

inline std::istream& operator>>(std::istream& in, Box&  box)
{
  return box.get(in);
}
#endif
