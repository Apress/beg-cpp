#ifndef DIMENSION_ERROR_H
#define DIMENSION_ERROR_H
#include<stdexcept>                         // For derived exception classes
#include <string>                           // For string type
using std::string;
using std::range_error;

class dimension_error : public range_error
{
public:
  using range_error::range_error;          // Inherit base constructors

  dimension_error(std::string str, double dim) : range_error {str + std::to_string(dim)} {}
};
#endif
