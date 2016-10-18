// Template type to encapsulate person objects.
/*
  A class template to store objects of type T in a vector.
  Type T must be derived from Person.
*/

#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include <memory>
#include <string>
#include <type_traits>
#include "Person.h"

using std::string;

template<typename T> class Group
{
  // Verify T is acceptable type
  static_assert(std::is_base_of<Person, T>::value, "Group template only usable with types derived from Person.");
protected:
  std::vector<std::shared_ptr<Person>> people;                     // Contains pointers to the T objects
  
public:
  Group(size_t space = 20){ people.reserve(space); }
  Group(const Group& people) = delete;                             // No copy contructor
  Group& operator=(const Group& people) = delete;                  // No assignment operator

  void add(const T& person)                                        // Add a person
  {
    people.push_back(std::shared_ptr<Person>(new T(person)));
  }

  std::shared_ptr<Person> find(const string& second_name);         // Find a person by name
  bool remove(const string& second_name);                          // Remove a person by name
  void clear(){ people.clear(); }                                  // Remove all
  std::ostream& put(std::ostream& out);                            // Output all
};

// Stream output operator for Group objects
template<typename T>
inline std::ostream& operator<<(std::ostream& out, Group<T>& group)
{
  return group.put(out);
}

// Find a person by name
template <typename T>
std::shared_ptr<Person> Group<T>::find(const string& second_name)  // Find a person by second name
{
  std::vector<size_t> found_indexes;
  for (size_t i {}; i < people.size(); ++i)
  {
    if (people.at(i)->getName().get_second_name() == second_name)
    {
      found_indexes.push_back(i);
    }
  }
  if (found_indexes.size() == 0)
  {
    std::cout << second_name << " not found." << std::endl;
    return nullptr;                                                    // Not found
  }
  if (found_indexes.size() == 1) return people.at(found_indexes[0]);   // Found one

  // Found more than one...
  std::cout << "Several people found with the name " << second_name << ". Choose from the following:\n";
  size_t index {};
  for (auto i : found_indexes)
  {
    std::cout << '[' << ++index << "] " << people.at(i)->getName() << std::endl;
  }
  std::cin >> index;
  return people.at(found_indexes[index - 1]);
}

// Remove a person by name
template <typename T> bool Group<T>::remove(const string& second_name)
{
  auto pperson = find(second_name);
  if (!pperson) return false;

  for (size_t i {}; i < people.size(); ++i)
  {
    if (pperson == people.at(i))
    {
      people.at(i) = people.back();                                // Overwrite with last element to delete it
      people.pop_back();                                           // Remove last element
      return true;
    }
  }
  return false;
}

// Write a Group<T> to a stream
template <typename T>
std::ostream& Group<T>::put(std::ostream& out)
{
  for (auto pperson : people)
  {
    pperson->put(out << std::endl);
  }

  return out;
}
#endif
