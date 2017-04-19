// Box.h
#ifndef BOX_H
#define BOX_H
#include <fstream>
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

  Box() = default;                                          // Default constructor

  Box(const Box& box)                                     // Copy constructor
    : length {box.length}, width {box.width}, height {box.height} {}

  double volume() const                                   // Calculate the volume
  {
    return length*width*height;
  }

  friend std::ostream& operator<<(std::ostream& stream, const Box& box);
  friend std::istream& operator>>(std::istream& in, Box& box);

  friend std::ifstream& read(std::ifstream& in, Box& box);
  friend std::ofstream& write(std::ofstream& out, Box& box);
};

// Stream insertion operator for Box objects
inline std::ostream&  operator<<(std::ostream& out, const  Box&  box)
{
  return out << std::setw(10) << box.length << ' '
    << std::setw(10) << box.width << ' '
    << std::setw(10) << box.height << '\n';
}

// Stream extraction operation for Box objects
inline std::istream&  operator>>(std::istream& in, Box&  box)
{
  return in >> box.length >> box.width >> box.height;
}

// Binary stream input for Box objects
inline std::ifstream& read(std::ifstream& in, Box& box)
{
  in.read(reinterpret_cast<char*>(&box.length), sizeof(box.length));
  in.read(reinterpret_cast<char*>(&box.width), sizeof(box.width));
  in.read(reinterpret_cast<char*>(&box.height), sizeof(box.height));
  return in;
}

// Binary stream output for Box objects
inline std::ofstream& write(std::ofstream& out, Box& box)
{
  out.write(reinterpret_cast<char*>(&box.length), sizeof(box.length));
  out.write(reinterpret_cast<char*>(&box.width), sizeof(box.width));
  out.write(reinterpret_cast<char*>(&box.height), sizeof(box.height));
  return out;
}
#endif
