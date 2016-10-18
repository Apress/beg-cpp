// Exercise 7.3 Replacing a word in text by asterisks.
// Because we are looking for the word regardless of case,
// the best way is to scan the text character by character.
#include <iostream>
#include <string> 
#include <cctype>
using std::string;

int main()
{
  string text;                                               // The text to be searched
  string word;                                               // Stores the word to be replaced
  char asterisk {'*'};
  std::cout << "Enter some text terminated by *:\n";
  std::getline(std::cin, text, '*');
  std::cout << "\nEnter the word to be replaced: ";
  std::cin >> word;
  string uc_word {word};
  for (auto& ch : uc_word)
    ch = std::toupper(ch);



  const string separators {" ,;:.\"!?'\n"};                  // Word  delimiters

  size_t start {text.find_first_not_of(separators)};         // First word start index
  size_t end {};                                             // Index for end of a word
  bool is_word {false};                                      // true when word is found
  while (start != string::npos)                              // Find the words
  {
    end = text.find_first_of(separators, start + 1);         // Find end of  word
    if (end == string::npos)                                 // Found  a separator?
      end = text.length();                                   // No, so set  to  last + 1

    // Compare the word found in uppercase with uc_word
    if (end - start == word.length())
    {
      is_word = true;                                        // Assume it is the word               
      for (size_t i {start}; i < end; ++i)                   
        if (uc_word[i - start] != toupper(text[i]))          // If a character differs...
        {
          is_word = false;                                   // ...it is not the word                                 
          break;      
        }
      if (is_word)                                           // If it is the word...
        for (size_t i {start}; i < end; ++i)                 // ... replace by asterisks
          text[i] = asterisk;
    }
    start = text.find_first_not_of(separators, end + 1);     // Find 1st character of next word
  }

  std::cout << std::endl << text << std::endl;
}
