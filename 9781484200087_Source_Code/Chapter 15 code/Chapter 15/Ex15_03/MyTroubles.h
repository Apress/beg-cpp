// MyTroubles.h Exception class definition
#ifndef MYTROUBLES_H
#define MYTROUBLES_H
#include <string>
using std::string;

class Trouble
{
private:
  string message;
public:
  Trouble(string str = "There's a problem") : message {str} {}
  string what() const { return message; }
};
#endif
