// Exercise 11.3 Integer.h
#ifndef INTEGER_H
#define INTEGER_H
class Integer
{
private:
  int n;

public:
  Integer(int m = 0);
  Integer(Integer& obj);                 // Copy constructor
//  int compare(const Integer obj) const;  // Compare function
  int compare(const Integer& obj) const; // Compare function with reference paramter
  int getValue() {return n;}
  void setValue(int m){ n = m; }
  void show();

  Integer* add(const Integer& obj);
  Integer* add(int m);
  Integer* subtract(const Integer& obj);
  Integer* subtract(int m);
  Integer* multiply(const Integer& obj);
  Integer* multiply(int m);
 
};
#endif