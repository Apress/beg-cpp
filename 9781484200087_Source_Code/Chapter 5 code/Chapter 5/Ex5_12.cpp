// Ex5_12.cpp
// Working with strings in an array
#include  <iostream>

int main()
{
  const size_t max_str{ 80 };      // Maximum string length including \0
  char stars[][max_str] {
      "Fatty Arbuckle", "Clara Bow",
      "Lassie", "Slim Pickens",
      "Boris Karloff", "Mae West",
      "Oliver Hardy", "Greta Garbo"
  };
  size_t choice{};

  std::cout << "Pick  a lucky  star! Enter  a number  between 1 and "
    << sizeof(stars) / sizeof(stars[0]) << ": ";
  std::cin >> choice;

  if (choice >= 1 && choice <= sizeof stars / sizeof stars[0])
  {
    std::cout << "Your lucky star is " << stars[choice - 1] << std::endl;
  }
  else
  {
    std::cout << "Sorry, you haven't got a lucky star." << std::endl;
  }
}
