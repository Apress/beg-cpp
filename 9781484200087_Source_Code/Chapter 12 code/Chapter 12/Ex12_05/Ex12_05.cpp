// Ex12_05.cpp
// Defining a destructor and the copy constructor
#include "Message.h"

// Ouput a copy of a Message object
void print(Message message)
{
  message.show();
}
int main()
{
  Message beware {"Careful"};
  Message warning;

  warning = beware;                    // Call assignment operator
  std::cout << "After assignment beware is:\n";
  beware.show();
  std::cout << "After assignment warning is:\n";
  warning.show();
}