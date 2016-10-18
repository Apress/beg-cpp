// Exercise 11.1 Implementing an Integer class
#include <iostream>
#include "Integer.h"

int main() 
{
  std::cout << "Create i with the value 10." << std::endl;
  Integer i {10};
  i.show();
  std::cout << "Change value  of i to 15." << std::endl;
  i.setValue(15);
  i.show();
 
  std::cout << "Create j with the value 5000." << std::endl;
  Integer j {5000};
  j.show();
  std::cout << "Set value of j to 150 times that of i." << std::endl;
  j.setValue(150*i.getValue());
  j.show();

  std::cout << "Create k with the value 789." << std::endl;
  Integer k {789};
  k.show();
  std::cout << "Set value of k to sum of i and j values." << std::endl;
  k.setValue(i.getValue()+j.getValue());
  k.show();
}