// Ex7_02.cpp
// Accessing characters  in a string
#include  <iostream>
#include  <string>
#include  <locale>
using  std::string;

int main()
{
  string text;                                   // Stores  the  input
  std::cout << "Enter  a line of  text:\n";
  std::getline(std::cin, text);                  // Read  a line including spaces

  int vowels{};                                  // Count of  vowels
  int consonants{};                              // Count of  consonants
  for (size_t i{}; i<text.length(); ++i)
  {
    if (isalpha(text[i]))                        // Check  for a letter
      switch (tolower(text[i]))                  // Convert to lowercase
    {
      case 'a': case 'e': case 'i': case 'o': case 'u':
        ++vowels;
        break;

      default:
        ++consonants;
        break;
    }
  }

  std::cout << "Your input contained " << vowels << " vowels and "
    << consonants << " consonants." << std::endl;
}
