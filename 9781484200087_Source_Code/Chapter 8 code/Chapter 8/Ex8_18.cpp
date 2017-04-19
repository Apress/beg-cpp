// Ex8_18.cpp
// Sorting words recursively
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
using std::string;
using PWord = std::shared_ptr<string>;
using PWords = std::vector<PWord>;

// Function prototypes
void swap(PWords& pwords, size_t first, size_t second);
void sort(PWords& pwords, size_t start, size_t end);
void extract_words(PWords& pwords, const string& text, const string& separators);
void show_words(const PWords& pwords);
size_t max_word_length(const PWords& pwords);

int main()
{
  PWords pwords;
  string text;                                                       // The string to be sorted
  const string separators{" ,.!?\"\n"};                              // Word delimiters

  // Read the string to be searched from the keyboard
  std::cout << "Enter a string terminated by *:" << std::endl;
  getline(std::cin, text, '*');

  extract_words(pwords, text, separators);
  if (pwords.size() == 0)
  {
    std::cout << "No words in text." << std::endl;
    return 0;
  }

  sort(pwords, 0, pwords.size() - 1);                                // Sort the words 
  show_words(pwords);                                                // Output the words
}

// Swap address at position first with address at position second
void swap(PWords& pwords, size_t first, size_t second)
{
  PWord temp{pwords[first]};
  pwords[first] = pwords[second];
  pwords[second] = temp;
}

// Sort strings in ascending sequence
// Addresses of words to be sorted are from words[start] to words[end]
void sort(PWords& pwords, size_t start, size_t end) 
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;                                                

  // Choose middle address to partition set
  swap(pwords, start, (start + end) / 2);                            // Swap middle address with start

  // Check words against chosen word
  size_t current{start};
  for (size_t i{start + 1}; i <= end; i++)
  {
    if (*(pwords[i]) < *(pwords[start]))                             // Is word less than chosen word?
      swap(pwords, ++current, i);                                    // Yes, so swap to the left
  }

  swap(pwords, start, current);                                      // Swap the chosen word with last in

  if (current > start) sort(pwords, start, current - 1);             // Sort left subset if exists
  if (end > current + 1) sort(pwords, current + 1, end);             // Sort right subset if exists
}

// Function to extract words from the text
void extract_words(PWords& pwords, const string& text, const string& separators)
{
  size_t start{text.find_first_not_of(separators)};                  // Start 1st word
  size_t end{};                                                      // Index for the end of a word

  while (start != string::npos)
  {
    end = text.find_first_of(separators, start + 1);                 // Find end separator
    if (end == string::npos)                                         // End of text?
      end = text.length();                                           // Yes, so set to last+1
    pwords.push_back(std::make_shared<string>(text.substr(start, end - start)));
    start = text.find_first_not_of(separators, end + 1);             // Find next word
  }
}

// Function to output the words
void show_words(const PWords& pwords)
{
  const size_t field_width{max_word_length(pwords) + 2};
  const size_t words_per_line{8};                                    // Word_per_line
  std::cout << std::left << std::setw(field_width) << *pwords[0];    // Output the first word

  size_t words_in_line{};                                            // Words in the current line
  for (size_t i{1}; i < pwords.size(); ++i)
  { // Output - words newline when initial letter changes or after 10 per line
    if ((*pwords[i])[0] != (*pwords[i - 1])[0] || ++words_in_line == words_per_line)
    {
      words_in_line = 0;
      std::cout << std::endl;
    }
    std::cout << std::setw(field_width) << *pwords[i];                     // Output a word
  }
  std::cout << std::endl;
}

// Find the maximum word length
size_t max_word_length(const PWords& pwords)
{
  size_t max{};
  for (auto& pword : pwords)
    if (max < pword->length()) max = pword->length();
  return max;
}
