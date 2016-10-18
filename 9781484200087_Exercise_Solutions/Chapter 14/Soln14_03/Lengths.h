// Exercise 14.3 Lengths.h
// Length classes with conversion operator functions

#ifndef LENGTHS_H
#define LENGTHS_H


// Class name declarations - we need these because we refer
// to the class names before they are defined.
class Inches;
class Yards;
class Meters;
class Perches;

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
  BaseLength(long n) : mm(n) {}                                                     // Constructor from millimeters
  virtual double length() const { return mm; };                                     // Return the length

  virtual operator Inches()const;                                                   // Conversion to Inches
  virtual operator Yards()const;                                                    // Conversion to Yards
  virtual operator Meters()const;                                                   // Conversion to Meters
  virtual operator Perches()const;                                                  // Conversion to Perches
  };

// If the derived classes did not define overrides for conversion to the same type
// the inherited conversion would be called which .
// would result in an error in the length displayed for the current type.
class Inches : public BaseLength
{
protected:
  double inches {};

public:
  Inches() = default;
  Inches(double ins) :BaseLength {static_cast<long>(0.5 + mmPerInch*ins)}, inches {ins} {}
  double length() const override { return inches; }                                 // Return the length

  // Inherited conversion to meters is OK
  operator Inches() const override { return *this; }
  operator Yards()const override;                                                   // Conversion to Yards
  operator Perches()const override;                                                 // Conversion to Perches

 };

class Meters: public BaseLength
{
protected:
  double meters {};

public:
  Meters() = default;
  Meters(double m) :BaseLength {static_cast<long>(0.5 + mmPerMeter*m)}, meters {m} {}
  double length() const override { return meters; }                                 // Return the length

  // All inherited conversion operator functions are OK
};

class Yards: public BaseLength
{
protected:
  double yards {};

public:
  Yards() = default;
  Yards(double yds) :BaseLength {static_cast<long>(0.5 + inchesPerYard*mmPerInch*yds)}, yards {yds} {}
  double length() const override { return yards; }                                  // Return the length

  // Inherited conversion to meters is OK
  operator Yards() const override { return *this; }
  operator Perches()const override;                                                 // Conversion to Perches
  operator Inches()const override;                                                  // Conversion to Inches
};

class Perches: public BaseLength 
{
protected:
  double perches {};

public:
  Perches():BaseLength(){}
  Perches(double pch) :BaseLength {static_cast<long>(0.5 + yardsPerPerch*inchesPerYard*mmPerInch*pch)}, perches {pch} {}
  double length() const override { return perches; }                                // Return the length

  operator Perches() const override { return *this; }
  operator Inches()const override;                                                  // Conversion to Perches
  operator Yards()const override;                                                   // Conversion to Yards
};

#endif