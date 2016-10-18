// Exercise 11.2 Integer.h

#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
private:
  int n;

public:
  Integer(int m = 0);
  Integer(Integer& obj);                   // Copy constructor
//  int compare(const Integer obj) const;  // Compare function
  int compare(const Integer& obj) const;   // Compare function with reference paramter
  int getValue() {return n;}
  void setValue(int m){ n = m; }
  void show();
};
#endif