// Exercise 7.4 Check for anagrams.
// There's more than one way to do this. 
// I chose to delete characters in one word that are common to both.
// If the length of thw word that has characters deleted is zero, they are anagrams.
#include <iostream>
#include <cctype>
#include <string>
using std::string;

int main() 
{
  string word1;
  string word2;

  std::cout << "Enter the first word: ";
  std::cin >> word1;
  std::cout << "Enter the second word: ";
  std::cin >> word2;

  // Test the pathological case of the strings being different lengths
  if (word1.length() != word2.length()) {
    std::cout << word1 << " and " << word2 << " are different lengths so they can't be anagrams!" << std::endl;
    return 0;
  }

  string word2_copy {word2};                                // Copy word2 - because we will delete characters
  // Loop over all the characters in word1
  for (size_t i {}; i < word1.length(); ++i)
  {
    // Loop over all the characters in word2
    for (size_t j {}; j < word2_copy.length(); j++)
      if (std::tolower(word2_copy[j]) == std::tolower(word1[i])) 
      {
        word2_copy.erase(j, 1);   // Character found so erase from word2
        break;
      }
  }

  std::cout << word1 << " and " << word2 << " are "
    << (word2_copy.length() ? "not" : "")
    << " anagrams of one another."
    << std::endl;
}