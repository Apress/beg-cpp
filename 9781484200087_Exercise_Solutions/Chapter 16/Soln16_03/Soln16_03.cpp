// Exercise 16.3 Exercising the SparseArray class template with the LinkedList class template
#include "SparseArrayT.h"
#include "LinkedListT.h"
#include <string>
#include <iostream>
#include <cctype>
using std::string;
using List = LinkedList <string>;

int main()
{
  string text;                               // Stores input prose or poem
  std::cout << "\nEnter a poem or prose over one or more lines."
            << "Terminate the input with #:\n";
  getline(std::cin, text, '#');

  SparseArray<List> lists;                   // Sparse array of linked lists
  string letters {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  // Extract words and store in the appropriate list
  // A list in the SparseArray is selected by the index in letters of the first letter in a word.
  string word;                                // Stores a word
  string separators {" \n\t,.\"?!;:"};       // Separators between words
  size_t start {};                           // Start of a word
  size_t end {};                             // separator position after a word
  while(string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start+1);
    word = text.substr(start,end-start);
    lists[letters.find(std::toupper(word[0]))].addTail(&word);
    start = end;
  }

  // List the words in order 5 to a line
  const size_t perline {5};
    size_t count {};                           // Word counter
  string* pStr;
  for (size_t i {}; i < 26; ++i)
  {
    if (!lists.element_exists(i))
      continue;
    pStr = lists[i].getHead();
    count = 0;

    while(pStr)
    {
      std::cout << *pStr << ' ';
      if(!(++count % perline))
        std::cout << std::endl;
      pStr = lists[i].getNext();
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}