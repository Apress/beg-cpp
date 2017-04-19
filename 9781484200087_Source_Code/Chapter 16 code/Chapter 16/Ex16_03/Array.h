// Array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>                        // For standard exception types
#include <string>                           // For to_string()
#include <type_traits>

template <typename T>
class Array
{
  static_assert(std::is_default_constructible<T>::value, "A default constructor is required.");
private:
  T* elements;                              // Array of type T
  size_t size;                              // Number of array elements

public:
  explicit Array(size_t arraySize);         // Constructor
  Array(const Array& array);                // Copy Constructor
  ~Array();                                 // Destructor
  T& operator[](size_t index);              // Subscript operator
  const T& operator[](size_t index) const;  // Subscript operator-const arrays
  Array& operator=(const Array& rhs);       // Assignment operator
  size_t getSize() { return size; }         // Accessor for size
};

// Constructor
template <typename T>                       // This is a template with parameter T 
inline Array<T>::Array(size_t arraySize) try : size {arraySize}, elements {new T[arraySize]}
{}
catch (std::bad_alloc& ) 
{ 
  std::cerr << "memory allocation failed for Array object creation.\n"; 
}

// Copy constructor
template <typename T>
inline Array<T>::Array(const Array& array) try : size {array.size}, elements {new T[array.size]}
{
  for (size_t i {}; i < size; ++i)
    elements[i] = array.elements[i];
}
catch (std::bad_alloc&)
{
  std::cerr << "memory allocation failed for Array object copy.\n";
}

// Destructor
template <typename T> inline Array<T>::~Array()
{
  delete[] elements;
}

// Subscript operator
template <typename T> inline T& Array<T>::operator[](size_t index)
{
  if (index >= size) throw std::out_of_range {"Index too large: " + std::to_string(index)};

  return elements[index];
}

// const subscript operator
template <typename T> inline const T& Array<T>::operator[](size_t index) const
{
  if (index >= size) throw std::out_of_range {"Index too large: " + std::to_string(index)};

  return elements[index];
}

// Assignment operator
template <typename T> inline Array<T>& Array<T>::operator=(const Array& rhs)
try
{
  if (&rhs != this)                         // If lhs != rhs...
  {                                         // ...do the assignment...
    if (elements)                           // If lhs array exists
      delete[] elements;                    // release the free store memory

    size = rhs.size;
    elements = new T[rhs.size];
    for (size_t i {}; i < size; ++i)
      elements[i] = rhs.elements[i];
  }
  return *this;                              // ... return lhs
}
catch (std::bad_alloc&)
{
  std::cerr << "memory allocation failed for Array assignment.\n";
}
#endif