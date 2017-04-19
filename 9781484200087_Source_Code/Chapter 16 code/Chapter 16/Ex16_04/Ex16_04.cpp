// Ex16_04.cpp
// Using a stack defined by nested class templates
#include "Stacks.h"
#include <iostream>
#include <string>
using std::string;

int main()
{
  const char* words[] {"The", "quick", "brown", "fox", "jumps"};
  Stack<const char*> wordStack;             // A stack of C-style strings

  for (size_t i {}; i < sizeof(words)/sizeof(words[0]) ; ++i)
    wordStack.push(words[i]);

  Stack<const char*> newStack {wordStack};   // Create a copy of the stack

  // Display the words in reverse order
  while(!newStack.isEmpty())
    std::cout << newStack.pop() << " ";
  std::cout << std::endl;

  // Reverse wordStack onto newStack
  while(!wordStack.isEmpty())
    newStack.push(wordStack.pop());

  // Display the words in original order
  while(!newStack.isEmpty())
    std::cout << newStack.pop() << " ";
  std::cout << std::endl;

  std::cout << std::endl << "Enter a line of text:" << std::endl;
  string text;
  std::getline(std::cin, text);             // Read a line into the string object

  Stack<const char> characters;             // A stack for characters

  for (size_t i {}; i < text.length(); ++i)
    characters.push(text[i]);               // Push the string characters onto the stack

  std::cout << std::endl;
  while(!characters.isEmpty())
    std::cout << characters.pop();          // Pop the characters off the stack

  std::cout << std::endl;
}
