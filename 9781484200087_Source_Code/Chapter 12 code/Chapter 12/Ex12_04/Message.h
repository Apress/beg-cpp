// Message.h
#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <string>
class Message
{
private:
  std::string* ptext;                   // Pointer to string

public:

  // Function to display a message
  void show() const
  {
    std::cout << "Message is: " << *ptext << std::endl;
  }

  // Constructor
  Message(const char* text = "No message")
  {
    ptext = new std::string {text};        // Allocate space for text
  }

  // Copy Constructor - uncomment the following statements to make the example work correctly
  //Message(const Message& message)
  //{
  //  ptext = new std::string(*message.ptext);   // Duplicate the object in the heap
  //}

  // Assignment operator
  Message& operator=(const Message& message)
  {
    if (this != &message)
      ptext = new std::string(*message.ptext);  // Duplicate the object in the heap

    return *this;                               // Return the left operand
  }

  // Destructor
  ~Message()
  {
    delete ptext;
  }
};
#endif