// Exercise 8.2 Reversing the order of a string of characters. 
/******************************************************************
The reverse() function works with an argument of type string, or a
C-style string terminated with '\0'.
*******************************************************************/
#include <iostream>
#include <string>
using std::string;

string reverse(string str1);

int main()
{
  string sentence;
  std::cout << "Enter a sequence of characters, then press 'Enter': " << std::endl;
  getline(std::cin, sentence);

  std::cout << std::endl
    << "Your sequence in reverse order is:\n";
  std::cout << reverse(sentence) << std::endl;

  std::cout << "Here is a demonstration of reverse() working with a C-style string:\n";

  char stuff[] {"abcdefg"};                      // C-style string
  std::cout << std::endl << "The original string is: \"" << stuff << "\"" << std::endl
    << "Reversed it becomes: \"" << reverse(stuff) << "\"" << std::endl;
}

// Reverse a string in place
// The code here is working with a copy of the argument
// so the original is not affected.
string reverse(string str)
{
  char temp {};
  size_t len {str.length()};
  for (size_t i {}; i < str.length() / 2; ++i)
  {
    temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
  return str;
}