// Ex9_03.cpp
// Sorting words in ascending or descending sequence
#include <iostream>
#include <iomanip>                      // For stream manipulators
#include <memory>                       // For smart pointers
#include <string>                       // for type string
#include <vector>                       // For vector<T> container
#include <functional>                   // For function<> type
#include <utility>                      // For swap() function template
using std::string;
using PWord = std::shared_ptr<string>;
using PWords = std::vector<PWord>;

// Function prototypes
void mysort(PWords& data, size_t start, size_t end, std::function<bool(const PWord, const PWord)> compare);
void extract_words(std::vector<std::shared_ptr<string>>& pwords, const string& text, const string& separators);
void show_words(const std::vector<std::shared_ptr<string>>& pwords);
size_t max_word_length(const std::vector<std::shared_ptr<string>>& pwords);

int main()
{
  PWords pwords;
  string text;                                                                                // The string to be sorted
  const string separators {" ,.!?\"\n"};                                                      // Word delimiters

  // Read the string to be searched from the keyboard
  std::cout << "Enter a string terminated by *:" << std::endl;
  getline(std::cin, text, '*');

  extract_words(pwords, text, separators);
  if (pwords.size() == 0)
  {
    std::cout << "No words in text." << std::endl;
    return 0;
  }
  size_t start {}, end {pwords.size() - 1};
  std::cout << "\nWords in ascending sequence:\n";
  mysort(pwords, start, end, [](const PWord p1, const PWord p2) {return *p1 < *p2; });        // Sort the words 
  show_words(pwords);                                                                         // Output the words
  std::cout << "\nWords in descending sequence:\n";
  mysort(pwords, start, end, [](const PWord p1, const PWord p2) {return *p1 > *p2; });        // Sort the words 
  show_words(pwords);                                                                         // Output the words
}

// Sort function that accepts a lambda expressing a comparison
void mysort(PWords& data, size_t start, size_t end, std::function<bool(const PWord, const PWord)> compare)
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle address to partition set
  std::swap(data[start], data[(start + end) / 2]);                                            // Swap middle address with start

  // Check words against chosen word
  size_t current {start};
  for (size_t i {start + 1} ; i <= end ; i++)
  {
    if (compare(data[i], data[start]))                                                        // Is word less than chosen word?
      std::swap(data[++current], data[i]);                                                    // Yes, so swap to the left
  }

  std::swap(data[start], data[current]);                                                      // Swap the chosen word with last in

  if (current > start) mysort(data, start, current - 1, compare);                             // Sort left subset if exists
  if (end > current + 1) mysort(data, current + 1, end, compare);                             // Sort right subset if exists
}

// Function to extract words from the text
void extract_words(std::vector<std::shared_ptr<string>>& pwords, const string& text, const string& separators)
{
  size_t start {text.find_first_not_of(separators)};                                          // Start 1st word
  size_t end {};                                                                              // Index for the end of a word

  while (start != string::npos)
  {
    end = text.find_first_of(separators, start + 1);                                          // Find end separator
    if (end == string::npos)                                                                  // End of text?
      end = text.length();                                                                    // Yes, so set to last+1
    pwords.push_back(std::make_shared<string>(text.substr(start, end - start)));
    start = text.find_first_not_of(separators, end + 1);                                      // Find next word
  }
}

// Function to output the words
void show_words(const std::vector<std::shared_ptr<string>>& pwords)
{
  const size_t field_width {max_word_length(pwords) + 2};
  const size_t words_per_line {8};                                                            // Word_per_line
  std::cout << std::left << std::setw(field_width) << *pwords[0];                             // Output the first word

  size_t words_in_line {};                                                                    // Words in the current line
  for (size_t i {1} ; i < pwords.size() ; ++i)
  { // Output - words newline when initial letter changes or after 10 per line
    if ((*pwords[i])[0] != (*pwords[i - 1])[0] || ++words_in_line == words_per_line)
    {
      words_in_line = 0;
      std::cout << std::endl;
    }
    std::cout << std::setw(field_width) << *pwords[i];                                        // Output a word
  }
  std::cout << std::endl;
}

// Find the maximum word length
size_t max_word_length(const std::vector<std::shared_ptr<string>>& pwords)
{
  size_t max {};
  for (auto& pword : pwords)
    if (max < pword->length()) max = pword->length();
  return max;
}
