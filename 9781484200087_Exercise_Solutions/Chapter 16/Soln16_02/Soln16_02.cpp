// Exercise 16.2 Exercising the LinkedList template class
// This program reverses the text that is entered
#include "LinkedListT.h"
#include <string>
#include <iostream>
using std::string;

int main()
{
  string text;                                   // Stores input prose or poem
  std::cout << "\nEnter a poem or prose over one or more lines."
            << "Terminate the input with #:\n";
  getline(std::cin, text, '#');

  LinkedList<string> words;                      // List to store words

  // Extract words and store in the list
  string separators(" ,.\"?!;:\n");              // Separators between words
  size_t start {};                               // Start of a word
  size_t end {};                                 // separator position after a word
  while(string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start+1);
    words.addTail(&text.substr(start,end-start));
    start = end;
  }

  // List the words 5 to a line
  std::cout << "\nThe words are:\n\n";
  auto pStr = words.getHead();
  size_t count {};                               // Word counter
  const size_t perline {5};                      // Worde per line
  while (pStr)
  {
    std::cout << *pStr << ' ';
    if (!(++count % perline))
      std::cout << std::endl;
    pStr = words.getNext();
  }
  std::cout << std::endl;

  // List the words in reverse order 5 to a line
  std::cout << "\nIn reverse order, the words are:\n\n";
  pStr = words.getTail();
  count = 0;
  while(pStr)
  {
    std::cout << *pStr << ' ';
    if(!(++count % perline))
      std::cout << std::endl;
    pStr = words.getPrevious();
  }
  std::cout << std::endl;
}