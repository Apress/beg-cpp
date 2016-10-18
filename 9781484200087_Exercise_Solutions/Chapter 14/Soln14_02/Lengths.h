// Exercise 14.2 Lengths.h
// Length classes 
// You could define the static data members using constexpr if your compiler supports it.
// This would remove the need to initialize them outside the class.
#ifndef LENGTHS_H
#define LENGTHS_H

class BaseLength
{
protected:
  long mm {};
  static double mmPerInch;
  static double mmPerMeter;
  static double inchesPerYard;
  static double yardsPerPerch;

public:
  BaseLength() = default;                                                           // Default constructor
  BaseLength(long n) : mm(n){}                                                      // Constructor from millimeters
  virtual double length() const { return mm; };                                     // Return the length
};

// Classes representing specific units store their own unit values.
// Lengths are also stored in the base class member mm.
// You could store all engths as just millimeters but this
// would result in an error of up to 1 mm in the length displayed.
// This is because the conversion of a length to an integer rounds down
// and there could be further small errors from decimal/binary floating point conversions. 
class Inches: public BaseLength
{
protected:
  double inches {};

public:
  Inches() = default;
  Inches(double ins) :BaseLength {static_cast<long>(0.5 + mmPerInch*ins)}, inches {ins} {}
  double length() const override { return inches; }                                 // Return the length
 };

class Meters: public BaseLength
{
protected:
  double meters {};

public:
  Meters() = default;
  Meters(double m) :BaseLength {static_cast<long>(0.5 + mmPerMeter*m)}, meters {m} {}
  double length() const override { return meters; }                                 // Return the length
};

class Yards: public BaseLength
{
protected:
  double yards {};

public:
  Yards() = default;
  Yards(double yds) :BaseLength {static_cast<long>(0.5 + inchesPerYard*mmPerInch*yds)}, yards {yds} {}
  double length() const override { return yards; }                                  // Return the length
};

class Perches: public BaseLength 
{
protected:
  double perches {};

public:
  Perches():BaseLength(){}
  Perches(double pch) :BaseLength {static_cast<long>(0.5 + yardsPerPerch*inchesPerYard*mmPerInch*pch)}, perches {pch} {}
  double length() const override { return perches; }                                // Return the length
};
#endif