// Ex11_09.cpp
// Using a nested class
#include  <iostream>
#include  <memory>
#include  <vector>
#include  <cstdlib>			// For random  number  generator
#include  <ctime>			  // For time  function
#include  "Box.h"
#include  "Truckload.h"

// Function to generate a random integer 1 to count
inline size_t random(size_t count)
{
  return 1 + static_cast<size_t> (count*static_cast<double>(std::rand()) / (RAND_MAX + 1.0));
}

int main()  
{
  const  size_t dimLimit {99};         // Upper limit on Box dimensions
  std::srand((unsigned)std::time(0));  // Initialize the  random  number  generator

  Truckload load1;                     // Create an empty list

  // Add 12 random Box objects to the list
  const size_t boxCount {12};
  for (size_t i {}; i < boxCount; ++i)
    load1.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

  std::cout << "The first list:\n";
  load1.listBoxes();

  // Find the largest Box in the  list
  ptr<Box> pBox {load1.getFirstBox()};
  ptr<Box> pNextBox {};
  while (pNextBox = load1.getNextBox())   // Assign &  then test pointer to  next  Box
    if (pBox->compare(*pNextBox) < 0)
        pBox = pNextBox;

  std::cout << "\nThe largest box in the first list is: ";
  pBox->listBox();
  std::cout << std::endl;
  load1.deleteBox(pBox);
  std::cout << "\nAfter deleting the largest box, the list contains:\n";
  load1.listBoxes();

  const  size_t nBoxes {20};                     // Number  of vector elements
  std::vector< ptr<Box> > boxes;                 // Array  of  Box objects

  for (size_t i {}; i < nBoxes; ++i)
    boxes.push_back(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

  Truckload load2(boxes);
  std::cout << "\nThe second list:\n";
  load2.listBoxes();


  pBox = load2.getFirstBox();
  while (pNextBox = load2.getNextBox())
    if (pBox->compare(*pNextBox) > 0)
      pBox = pNextBox;

  std::cout << "\nThe smallest box in the second list is";
  pBox->listBox();
  std::cout << std::endl;
}
