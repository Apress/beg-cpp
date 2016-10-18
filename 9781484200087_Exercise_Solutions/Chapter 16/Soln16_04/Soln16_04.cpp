// Exercise 16.4 Exercising the SparseArray class template for an array of arrays
/*
The example uses a SparseArray of elements that are SparseArray objects,
each of which stores words that have the same initial letter, ignoring case.
This is different from Soln16_03 where the linked list stored pointer to words.
The insert() function is used to add to an array of words with a given inital letter.
*/
#include "SparseArrayT.h"
#include <string>
#include <iostream>
using std::string;

int main()
{
  string text;                               // Stores input prose or poem
  std::cout << "\nEnter a poem or prose over one or more lines."
    << "Terminate the input with #:\n";
  getline(std::cin, text, '#');

  SparseArray< SparseArray<string> > arrays; // Sparse array of arrays of strings
  string letters {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  // Extract words and store in the appropriate list
  string word;                                // Stores a word
  string separators {" \n\t,.\"?!;:"};       // Separators between words
  size_t start {};                           // Start of a word
  size_t end {};                             // separator position after a word
  while (string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start + 1);
    word = text.substr(start, end - start);
    arrays[letters.find(toupper(word[0]))].insert(&word);
    start = end;
  }

  // List the words in order 5 to a line
  const size_t perline {5};
  size_t count {};                           // Word counter
  size_t j {};
  for (size_t i {}; i < 26; ++i)
  {
    if (!arrays.element_exists(i))
      continue;
    j = 0;
    count = 0;
    while ((word = arrays[i][j++]).length())
    {
      std::cout << word << ' ';
      if (!(++count % perline))
        std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}