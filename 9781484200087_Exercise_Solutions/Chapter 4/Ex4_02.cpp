// Exercise 4.2 Using nested ifs and a logical && to check the value of an integer.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int value = 0;

  cout << "Please enter an integer between 1 and 100: ";
  cin >> value;
  cout << endl;

  if ((value >= 1) && (value <= 100)) {
    if (value > 50)
      cout << "The integer is greater than 50." << endl;
    else if (value < 50)
      cout << "The integer is less than 50." << endl;
    else
      cout << "The integer you entered is 50." << endl;
  }
  else
    cout << "The integer is not between 1 and 100." << endl;

  return 0;
}