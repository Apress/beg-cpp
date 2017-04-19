// Ex15_03.cpp
// Throw an exception object
#include <iostream>
#include "MyTroubles.h"

int main()
{
  for (int i {}; i < 2; ++i)
  {
    try
    {
      if (i == 0)
        throw Trouble {};
      else
        throw Trouble {"Nobody knows the trouble I've seen..."};
    }
    catch (const Trouble& t)
    {
      std::cout << "Exception: " << t.what() << std::endl;
    }
  }
}