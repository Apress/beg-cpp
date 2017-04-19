// Ex8_07A.cpp
// Using a reference parameter and creating a vector on the heap
#include  <iostream>
#include  <iomanip>
#include  <string> 
#include  <vector> 
#include  <memory> 
using std::string;
using std::vector;
std::shared_ptr<vector<string>> find_words(const string& str, const string& separators);
void list_words(const std::shared_ptr<vector<string>> pWords);

int main()
{
  string text;                                               // The string to  be searched
  std::cout << "Enter some text terminated by *:\n";
  std::getline(std::cin, text, '*');

  const string separators{ " ,;:.\"!?'\n" };                 // Word  delimiters

  auto pWords = find_words(text, separators);
  list_words(pWords);
}

std::shared_ptr<vector<string>> find_words(const string& str, const string& separators)
{
  auto pWords = std::make_shared<vector<string>>();         // Vector of words
  size_t start{ str.find_first_not_of(separators) };        // First word start index
  size_t end{};                                             // Index for end of a word

  while (start != string::npos)                              // Find the words
  {
    end = str.find_first_of(separators, start + 1);          // Find end of  word
    if (end == string::npos)                                 // Found  a separator?
      end = str.length();                                    // No, so set  to  last + 1
    pWords->push_back(str.substr(start, end - start));       // Store the word
    start = str.find_first_not_of(separators, end + 1);      // Find 1st character of next word
  }
  return pWords;
}

void list_words(const std::shared_ptr<vector<string>> pWords)
{
  std::cout << "Your string contains the following " << pWords->size() << " words:\n";
  size_t count{};                                            // Number output
  for (const auto& word : *pWords)
  {
    std::cout << std::setw(15) << word;
    if (!(++count % 5))
      std::cout << std::endl;
  }
  std::cout << std::endl;
}
