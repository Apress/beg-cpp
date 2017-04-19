// Ex5_11.cpp
// Classifying  the  letters in a string
#include  <iostream>
#include  <locale>

int main()
{
  const  int maxlength{ 100 };              // Array  size
  char text[maxlength] {};                  // Array  to  hold  input  string

  std::cout << "Enter  a line of  text:" << std::endl;
  // Read  a line of  characters  including spaces
  std::cin.getline(text, maxlength);
  std::cout << "You entered:\n" << text << std::endl;

  size_t vowels{};                          // Count of  vowels
  size_t consonants{};                      // Count of  consonants
  for (int i{}; text[i] != '\0'; i++)
  {
    if (isalpha(text[i]))                   // If it is a letter...
    {
      switch (tolower(text[i]))
      {                                     // ...check lowercase...
      case 'a': case 'e': case 'i': case 'o': case 'u':
        vowels++;                           // ...it is a vowel
        break;

      default:
        consonants++;                       // ...it is a consonant
      }
    }
  }
  std::cout << "Your input  contained " << vowels << " vowels and "
            << consonants << " consonants." << std::endl;
}
