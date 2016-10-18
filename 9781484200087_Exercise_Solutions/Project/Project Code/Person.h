// Represents a generic person
/*
A Person is defined by a Name, an Address, and a Phone number.
A specific Person is created from by reading the name, address and phone from a stream.
Input and output are supported through virtual get() and put() member functions.
This allows the operator functions for >> and << to call get() and put() polymorphically
as long as derived classes iplement get() and put()
*/
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Name.h"
#include "Address.h"
#include "Phone.h"
using std::string;

class Person
{
protected:
  Name name;
  Address address;
  Phone phone;

public:
  Person() = default;
  // Public Get member functions
  Name get_Name() { return name; }
  Address get_Address() { return address; }
  Phone get_phone() const { return phone; }

  // Public Set member functions
  void set_Name(Name& new_name) { name = new_name; }
  void set_Address(Address& addr) {address = addr;  }
  void set_phone(Phone& phne)  { phone = phne;  }

  // Public Get member functions
  Name getName() { return name; }
  Address getAddress() { return address; }
  Phone getPhone()  { return phone; }

  // Public virtual member functions
  virtual std::istream& get(std::istream& in);
  virtual std::ostream& put(std::ostream& out);
};

// Stream output
inline std::ostream& Person::put(std::ostream& out)
{
  out << name << address << phone;
  return out;
}

// Stream output operator
inline std::ostream& operator<<(std::ostream& out, Person& person)
{
  return person.put(out);
}

// Reading from a stream is prompted when it is not a file stream
inline std::istream& Person::get(std::istream& in)
{
  in >> name >> address >> phone;
  return in;
}

// Stream input operator
inline std::istream& operator>>(std::istream& in, Person& person)
{
  return person.get(in);
}
#endif