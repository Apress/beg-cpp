// Exercise 16.3 Lengths.cpp
// Length classes implementations

#include "Lengths.h"

// Initialize static data members
double BaseLength::mmPerInch {25.4};
double BaseLength::mmPerMeter {1000.0};
double BaseLength::inchesPerYard {36.0};
double BaseLength::yardsPerPerch {5.5};

BaseLength::operator Inches()const
{
  return Inches {mm / mmPerInch};
}                                  // Conversion to Inches
BaseLength::operator Yards()const
{
  return Yards {mm / (mmPerInch*inchesPerYard)};
}                   // Conversion to Yards
BaseLength::operator Meters()const
{
  return Meters {mm / mmPerMeter};
}                                 // Conversion to Meters
BaseLength::operator Perches()const
{
  return Perches {mm / (mmPerInch*inchesPerYard*yardsPerPerch)};
}   // Conversion to Perches

Inches::operator Yards()const
{
  return Yards {inches / inchesPerYard};
}                           // Conversion to Yards
Inches::operator Perches()const
{
  return Perches {inches / (inchesPerYard*yardsPerPerch)};
}         // Conversion to Perches

Yards::operator Perches()const
{
  return Perches {yards / yardsPerPerch};
}                          // Conversion to Perches
Yards::operator Inches()const
{
  return Inches {yards * inchesPerYard};
}                           // Conversion to Inches

Perches::operator Inches()const
{
  return Inches {perches * yardsPerPerch*inchesPerYard};
}           // Conversion to Perches
Perches::operator Yards()const
{
  return Yards {perches * yardsPerPerch};
}                          // Conversion to Yards
