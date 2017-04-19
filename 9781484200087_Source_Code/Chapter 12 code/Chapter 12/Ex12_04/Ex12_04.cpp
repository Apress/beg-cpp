// Ex12_04.cpp
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
  print(beware);
  std::cout << "After print() call, output the beware directly:\n";
  beware.show();
}