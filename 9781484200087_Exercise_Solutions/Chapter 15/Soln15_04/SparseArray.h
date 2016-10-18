// Exercise 15.4 SparseArray.h
// SparseArray class definition - stores pointers to strings

#ifndef SPARSEARRAY_H
#define SPARSEARRAY_H
#include <string>
#include <memory>
using std::string;

class SparseArray
{
// Local using declarations - in scope of SparseArray class
class Element;
using PElement = std::shared_ptr<Element>;
private:
  PElement pFirst;                                                        // Pointer to first non-zero element element
  PElement pLast;                                                         // Pointer to last non-zero element element
  size_t maxElements {};

public:
  SparseArray(size_t n) : maxElements {n} {}                              // Constructor
  SparseArray(const SparseArray& array);                                  // Copy constructor
  SparseArray& operator=(const SparseArray& array);                       // Assignment operator
  Element& operator[](size_t index);                                      // Subscript SparseArray
  void show();                                                            // display array elements

private:
  // Element class definition
  class Element
  {
  public:
    size_t index {};                                                   // Index of element
    double value {};                                                   // Element value
    PElement pNext {};                                                 // Pointer to next element
    PElement pPrevious {};                                             // Pointer to previous element

    Element(size_t newIndex) : index(newIndex) {}                        // Constructor
    Element(const Element& element) : index(element.index), value {element.value} {}  // Copy constructor

    // Assign an Element to an Element
    Element& operator= (Element& element)
    {
      value = element.value;
      return *this;
    }

    // Assign a value to an element
    Element& operator= (double v)
    {
      value = v;
      return *this;
    }

    operator double() { return value; }
  };
};

#endif //SPARSEARRAY_H