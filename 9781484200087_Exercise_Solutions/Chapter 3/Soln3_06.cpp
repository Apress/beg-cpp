// Exercise 3.6 Using an enumeration type for colors.
// Of course, you have to research the RBG components for the colors.

#include <iostream>
#include <iomanip>

int main()
{
  const unsigned int R {0x00FF0000};
  const unsigned int G {0x0000FF00};
  const unsigned int B {0x000000FF};
  enum class Color :unsigned int{ Red = R, Green = G, Yellow = R | G, Purple = R | B, Blue = B, Black = 0, White = R | G | B };

  Color color1 {Color::Yellow};
  Color color2 {Color::Purple};
  Color color3 {Color::Green};
  unsigned int color {static_cast<unsigned int>(color1)};                                 // Get the enumerator value
  std::cout << std::setw(38) << "The components of color1 (yellow) are:"
    << "  Red:" << std::setw(3) << ((color & R) >> 16)
    << "  Green:" << std::setw(3) << ((color & G) >> 8)
    << "  Blue:" << std::setw(3) << (color & B) << std::endl;

  color = static_cast<unsigned int>(color2);
  std::cout << std::setw(38) << "The components of color2 (purple) are:"
    << "  Red:" << std::setw(3) << ((color & R) >> 16)
    << "  Green:" << std::setw(3) << ((color & G) >> 8)
    << "  Blue:" << std::setw(3) << (color & B) << std::endl;

  color = static_cast<unsigned int>(color3);
  std::cout << std::setw(38) << "The components of color3 (green) are:"
    << "  Red:" << std::setw(3) << ((color & R) >> 16)
    << "  Green:" << std::setw(3) << ((color & G) >> 8)
    << "  Blue:" << std::setw(3) << (color & B) << std::endl;
}