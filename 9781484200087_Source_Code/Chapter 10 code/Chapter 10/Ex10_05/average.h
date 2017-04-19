// average.h
#ifndef AVERAGE_H
#define AVERAGE_H

#include <type_traits>
#include <vector>

template<class T>
T average(const std::vector<T>& values)
{
  static_assert(std::is_arithmetic<T>::value,
    "Type parameter for average() must be arithmetic.");
  T sum{};
  for (auto& value : values)
    sum += value;
  return sum / values.size();
}
#endif
