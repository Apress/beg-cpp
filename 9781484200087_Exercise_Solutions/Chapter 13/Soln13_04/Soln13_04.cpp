// Exercise 13.4 Working with Employee and Executive objects

#include <iostream>
#include <vector>
#include "Person.h"

int main()
{
  std::vector<Employee> employees {
                                    Employee(21, "Randy Marathon", 'm', 34567),
                                    Employee(32, "Anna Pothecary", 'f', 34578),
                                    Employee(46, "Peter Out", 'm', 34589),
                                    Employee(37, "Sheila Rangeit", 'f', 34598),
                                    Employee(65, "Jack Ittin", 'm', 34667)
                                  };

  for(auto& employee : employees)
    employee.who();

  std::cout << std::endl;

  std::vector<Executive> executives {
                                      Executive(44, "Irwin Pootlemeyer", 'm', 35567),
                                      Executive(32, "Alexa Workwell", 'f', 35578),
                                      Executive(42, "Steve Stove", 'm', 35589),
                                      Executive(33, "Sue Neenuf", 'f', 35598),
                                      Executive(29, "Melanie Clair", 'f', 35667)
                                    };

  for (auto& executive : executives)
  {
    executive.who();
    executive.Employee::who();
  }
}