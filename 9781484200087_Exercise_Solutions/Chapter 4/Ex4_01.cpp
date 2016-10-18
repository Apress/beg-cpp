// Exercise 4.1 Testing for exact division of one integer by another. 
//              We can use an if statement to check that the input is valid 
//              and we can use another to arrange the input as we need. 
//              Then we use an if-else to generate the appropriate output.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int value1 = 0;
  int value2 = 0;
  int remainder = 0;

  cout << "Please input two positive integers, separated by a space: ";
  cin >> value1 >> value2;
  cout << endl;

  if((value1 <= 0) || (value2 <= 0)) {      // Valid input?
    cout << "Sorry - positive integers only." << endl;
    return 1;
  }

  if(value1 < value2) {                     // Ensure that value1 is not smaller than value2
    int temp = value1;                      // ... swap if necessary
    value1 = value2;
    value2 = temp;
  }

  /*********************************************
    Note that we could write the if statement above as:

    if(value1 <value2){
      value1 ^= value2;
      value2 ^= value1;
      value1 ^= value2;
    }

    // Although it's interesting, it doesn't exactly make the code clearer.
   
   ********************************************/

  remainder = value1 % value2;

  if(0 == remainder)
    cout << value2 << " divides into " << value1 << " exactly. " << endl;
  else 
    cout << value1 << " is not exactly divisible by " << value2 << endl;

  return 0;
}