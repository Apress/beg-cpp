// Array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>                        // For standard exception types
#include <string>                           // For to_string()

template <typename T, int startIndex>
class Array
{
private:
  T* elements;                              // Array of type T
  size_t size;                              // Number of array elements

public:
  explicit Array(size_t arraySize);         // Constructor
  Array(const Array& array);                // Copy Constructor
  ~Array();                                 // Destructor
  T& operator[](int index);                 // Subscript operator
  const T& operator[](int index) const;     // Subscript operator-const arrays
  Array& operator=(const Array& rhs);       // Assignment operator
  size_t getSize() { return size; }         // Accessor for size
};

// Constructor
template <typename T, int startIndex>
inline Array<T, startIndex>::Array(size_t arraySize) : size {arraySize}, elements {new T[arraySize]}
{}

// Copy constructor
template <typename T, int startIndex>
inline Array<T, startIndex>::Array(const Array& array) :
size {array.size}, elements {new T[array.size]}
{
  for (size_t i {} ; i < size ; ++i)
    elements[i] = array.elements[i];
}

// Destructor
template <typename T, int startIndex>
inline Array<T, startIndex>::~Array()
{
  delete[] elements;
}

// Subscript operator
template <typename T, int startIndex>
T& Array<T, startIndex>::operator[](int index)
{
  if (index > startIndex + static_cast<int>(size) - 1)
    throw std::out_of_range {"Index too large: " + std::to_string(index)};

  if (index < startIndex)
    throw std::out_of_range {"Index too small: " + std::to_string(index)};

  return elements[index - startIndex];
}

// const subscript operator
template <typename T, int startIndex>
const T& Array<T, startIndex>::operator[](int index) const
{
  if (index > startIndex + static_cast<int>(size) - 1)
    throw std::out_of_range {"Index too large: " + std::to_string(index)};

  if (index < startIndex)
    throw std::out_of_range {"Index too small: " : +s td::to_string(index)};

  return elements[index - startIndex];
}


// Assignment operator
template <typename T, int startIndex>
Array<T, startIndex>& Array<T, startIndex>::operator=(const Array& rhs)
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
  return *this;                            // ... return lhs
}

#endif