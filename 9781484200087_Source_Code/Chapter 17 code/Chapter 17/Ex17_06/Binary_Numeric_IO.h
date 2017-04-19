// Binary_Numeric_IO.h
#ifndef BINARY_NUMERIC_IO_H
#define BINARY_NUMERIC_IO_H

#include <type_traits>                      // For type testing templates
#include <fstream>                          // For file streams
#include <array>                            // For array containers
#include <vector>                           // For vector containers
#include <stdexcept>                        // For standard exception types

// Write numeric values
template <typename T>
void  write(std::ostream& out, T value)
{
  static_assert(std::is_arithmetic<T>::value, "Only for use with numeric types.");
  out.write(reinterpret_cast<char*>(&value), sizeof(T));
}

// Read numeric values
template <typename T>
void  read(std::istream& in, T& value)
{
  static_assert(std::is_arithmetic<T>::value, "Only for use with numeric types.");
  in.read(reinterpret_cast<char*>(&value), sizeof(T));
}

template <typename T>
void  write(std::ostream& out, T* values, size_t length)
{
  write(out, length);
  for (size_t i {}; i< length; ++i)
    write(out, values[i]);
}

template <typename T>
size_t read(std::istream& in, T* values)
{

  size_t length {};
  read(in, length);
  size_t i {};
  for (; i < length; ++i)
  {
    read(in, values[i]);
    if (!in) break;
  }
  return i;
}

// Write array container of numeric values
template <typename T, size_t N>
void  write(std::ostream& out, std::array<T, N>& values)
{
  write(out, N);
  for (size_t i {}; i < N; ++i)
    write(out, values[i]);
}

// Read array container of numeric values
template <typename T, size_t N>
size_t read(std::istream& in, std::array<T, N>& values)
{
  size_t length {};
  read(in, length);
  if (N < length) throw std::invalid_argument {"Too few elements in array container."};
  size_t i {};
  for (; i < length; ++i)
  {
    read(in, values[i]);
    if (!in) break;
  }
  return i;
}

// Write vectors of numeric values
template <typename T>
void  write(std::ostream& out, std::vector<T>& values)
{
  write(out, values.size());
  for (T x : values)
    write(out, x);
}

// Read vectors of numeric values
template <typename T>
size_t read(std::istream& in, std::vector<T>& values)
{
  size_t length {};
  read(in, length);
  T value {};
  size_t i {};
  for (; i < length; ++i)
  {
    read(in, value);
    if (!in) break;
    values.push_back(value);
  }
  return i;
}
#endif
