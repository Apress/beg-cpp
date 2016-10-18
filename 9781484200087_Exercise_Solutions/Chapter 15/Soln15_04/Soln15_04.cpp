// Exercise 15.4 Exercising the SparseArray class
/*
This is trickier than it looks. Throwing exceptions is the easy bit.
The hard bit is defining SparseArray to allow operations on elements to work as you would expect.
An important part of this is the operator double() member of the inner Element class.
This allows the compiler to insert implicit casts when required, which allows arithmetic operations
between SparseArray elements.
Note that operator[]() for the SparseArray class returns an object of type SparseArray::Element.
This is necessary to allow new values to be assigned to an element.
The compiler can convert this object to its value whenever it is required by the context.
*/
#include "SparseArray.h"
#include <iostream>
#include <exception>

int main()
{
  SparseArray values {50};  // Create a sparse array with capacity for 50

  // Exercise subscripting
  try
  {
    values[10] = 20;
    values[15] = 30;
    values[21] = 40;
    values[32] = 25;
    values[44] = 22;
    values[1] = values[10] + values[15];
    values[16] = values[15] + 1;
    values[17] = 2 + values[16];
    values[2] = values[21] + values[32];
    values[5] = values[1] + values[2] + values[44];
    std::cout << "values[2] = " << values[2] << std::endl;
    std::cout << "values[10] = " << values[10] << std::endl;
    std::cout << "Product of values[2] and values[10] is " << values[2] * values[10] << std::endl;
    values.show();
    values[14] = values[60];                         // Causes an exception to be thrown - out of range index
  }
  catch(std::exception& e)
  {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  // Exercise the copy constructor and assignment operator
  try
  {
    SparseArray copies {values};
    copies.show();
    copies[0] = values[5];
    values = copies;
    values.show();
  }
  catch(std::exception& e)
  {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}