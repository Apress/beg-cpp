// Exercise 6.5 Storing  student ages in dynamic array containers
// This tests how well you manage to separate different levels of pointers.
// Because we use smart pointers, releasing free store memory is taken care of automatically.
// I used some type aliases to make the code a bit clearer.

#include <iostream>
#include <iomanip>
#include <cctype>
#include <memory>
#include <vector>
using Class = std::vector<size_t>;                     // Type alias for vector storing the ages for student in a class
using PClass = std::shared_ptr<Class>;                  // Type alias for a smart pointer to a Class
using PClasses = std::vector<PClass>;                   // Type alias for a vector of pointers to Class objects

int main()
{
  auto pclasses = std::make_shared <PClasses>();       // Pointer to vector of pointers to Class objects
  size_t age {};
  PClass pclass;
  char answer {};
  while (true)
  {
    pclass = std::make_shared<Class>();
    pclasses->push_back(pclass);

    std::cout << "Enter ages for the class, enter 0 to end:\n";
    while (true)
    {
      std::cin >> age;
      if (!age) break;
      pclass->push_back(age);
    }
    std::cout << "Do you want to enter ages for another class(Y or N): ";
    std::cin >> answer;
    if (std::toupper(answer) == 'N') break;
  }

  const size_t perline {5};
  size_t count {};
  size_t class_id {};
  for (auto& pclass : *pclasses)
  {
    count = 0;
    std::cout << "\nAges of student in class " << ++class_id << ":\n";
    for (auto age : *pclass)
    {
      std::cout << std::setw(5) << age;
      if (++count % perline) continue;
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}