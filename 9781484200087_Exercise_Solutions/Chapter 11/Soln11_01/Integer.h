// Exercise 11.1 Integer.h

#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
private:
  int n;

public:
  Integer(int m);
  int getValue() {return n;}
  void setValue(int m){ n = m; }
  void show();
};
#endif