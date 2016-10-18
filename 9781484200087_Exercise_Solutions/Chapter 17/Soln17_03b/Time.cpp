// Exercise 17.3b Time.cpp
// Time class implementation

#include "Time.h"
#include <iomanip>
#include <iostream>

// Constructor
Time::Time(int h, int m, int s)
{
  seconds = s%60;                      // Seconds left after removing minutes
  minutes = m + s/60;                  // Minutes plus minutes from seconds
  hours = h + minutes/60;              // Hours plus hours from minutes
  minutes %= 60;                       // Minutes left after removing hours
}

// Insertion operator
std::ostream& operator <<(std::ostream& out, const Time& rT)
{
  out << ' ' << rT.getHours() << ':';
  char fillCh {out.fill('0')};                             // Set fill for leading zeros

  out << std::setw(2) << rT.getMinutes() << ':' 
      << std::setw(2) << rT.getSeconds() << ' '; 
  out.fill(fillCh);                                        // Restore old fill character
  return out;
}

// Extraction operator
std::istream& operator>> (std::istream& in, Time& rT)
{
  char ch {};                                              // Stores ':'
  in >> rT.hours >> ch >> rT.minutes >> ch >> rT.seconds;

  // Ensure seconds and minutes less than 60
  rT.minutes += rT.seconds/60;
  rT.hours += rT.minutes/60;
  rT.minutes %= 60;
  rT.seconds %= 60;
  return in;
}