// Exercise 7.5 Finding words that begin with a given letter.
// If you wanted the words ordered by the first letter, you could sort the contents of letter first.
// You could also retain all the sets of words for each letter in a separate vector for each set.
// Of course, you don't know how many sets will be required.
// You could accommodate this by creating a vector of smart pointers to the vectors to contain the words,
// then use std::make_shared() to create a vector for each starting letter and store its address in the vector of pointers.
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string> 
#include <vector> 
using std::string;

int main()
{
  string text;                                               // The text to be searched
  string letters;
  std::cout << "Enter some text terminated by *:\n";
  std::getline(std::cin, text, '*');
  std::cout << "\nEnter the starting letters for the words you want to find: ";
  std::cin >> letters;

  const string separators {" ,;:.\"!?'\n"};                    // Word  delimiters
  std::vector<string> words;                                   // Words found
  const size_t perline {5};                                    // Words output per line
  size_t count {};                                             // Number of words found
  for (auto ch : letters)
  {
    size_t start {text.find_first_not_of(separators)};         // First word start index
    size_t end {};                                             // Index for end of a word
    string word;                                               // Stores a word
    size_t max_length {};                                      // Maximum word length
    while (start != string::npos)                              // Find the words
    {
      end = text.find_first_of(separators, start + 1);         // Find end of  word
      if (end == string::npos)                                 // Found  a separator?
        end = text.length();                                   // No, so set  to  last + 1
      word = text.substr(start, end - start);                  // Record the word
      if (std::toupper(word[0]) == std::toupper(ch))           // If it begins with the current letter...
      {
        words.push_back(word);                                 // ...save the word
        if (max_length < word.length()) max_length = word.length();
      }

      start = text.find_first_not_of(separators, end + 1);     // Find 1st character of next word
    }
    // List words for current letter
    max_length += 2;
    std::cout << "\nWords beginning with '" << ch << "' are:\n";
    for (auto& word : words)
    {
      std::cout << std::setw(max_length) << std::left << word;
      if (++count % perline) continue;
      std::cout << std::endl;
    }
    std::cout << std::endl;
    words.clear();
    count = 0;
  }
}
