/*
***************************************************************
*
* MainProg.cpp
  This file includes the global functions for the program,
  some of which are called by class members.

  It also define global variables that store the file paths
  and variables that store the collections of students and teachers.

  There is no provision for entering file paths but this can be easily
  implemented, either through command line entries or through
  prompted input from the keyboard.
* 
***************************************************************
*/


// standard library includes
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

#include "Student.h"
#include "Teacher.h"
#include "Group.h"

using std::string;

// Global variables
Group<Student> students;                                            // All students
Group<Teacher> teachers;                                            // All teachers
static string students_file {"D:/Example_Data/students_file.txt"};  // Name and path for students file
static string teachers_file {"D:/Example_Data/teachers_file.txt"};  // Name and path for teachers file

// Function Prototypes
void load_students();                                           // Loads Student objects from a file if it exists
void load_teachers();                                           // Loads Teacher objects from a file if it exists
bool isFile(std::ios& in);                                      // Returns true if stream is a file
bool notFile(std::ios& in);                                     // Returns true if not a file stream
bool isInteger(string s);                                       // Returns true if s contains only digits
void display_records();                                         // Output all students or all teachers
char choose_person_type();                                      // Select a student or a teacher
void add_record();                                              // Add a student or a techer record
void delete_record();                                           // Delete a student or a teacher record
void delete_all_records();                                      // Delete all teachers or all students
void find_record();                                             // Find and display student or teacher record
void save_records();                                            // Save all student and teacher records to files

/* 
******************************************************
* Function: main
* return: int
* parameters: none
*
* Description:
* Start of the program.  This function will display 
* the Main Menu.
* You could add paramters to allow optional specification
* of the file names to replace the defaults.
******************************************************
*/

int main()
{
  load_students();
  load_teachers();
  char option {};                       // User input

  while (true)
  {
    // Display the Main Menu
    std::cout << std::endl << "MAIN MENU";
    std::cout << std::endl << "---------";
    std::cout << std::endl << "(A)dd a record";
    std::cout << std::endl << "(D)elete a record";
    std::cout << std::endl << "(C)lear a set of records";
    std::cout << std::endl << "(S)earch for a record";
    std::cout << std::endl << "Displa(Y) a set of records";
    std::cout << std::endl << "(Q)uit the Program" << std::endl;
    std::cout << std::endl << "Enter Selection: ";

    std::cin >> option;
    switch (std::toupper(option))
    {
    case 'A':
      // Add a record
      add_record();
      break;
    case 'D':
      // Delete a record
      delete_record();
      break;
    case 'C':
      // Delete all the records.
      delete_all_records();
      break;
    case 'S':
      // Search for a record
      find_record();
      break;
    case 'Y':
      // Display records
      display_records();
      break;
    case 'V':
      // Save the records to disk
      save_records();
      break;
    case 'Q':
      save_records();
      std::cout << "Ending the program." << std::endl;
      return 0;
    default:
      std::cout << std::endl << "Invalid choice.";
      break;
    }
  }
}

/*
******************************************************
* Function: load_students
* return: none
* parameters: none
*
* Description:
* Loads Student objects from the file identified by
* students_file if it exists.
******************************************************
*/
void load_students()
{
  std::cout << "Loading students...\n";
  Student student;
  std::ifstream infile {students_file};                                 // Open the file to read it
  if (infile.is_open())                                                 // If it is open...
  {                                                                     // ...it exists, so read it
    while (true)
    {
      infile >> student;                                                // Read a student and...
      if (!infile) break;
      students.add(student);                                            // ...add the student to the group.
    }
    infile.close();
    std::cout << "Students loaded from file." << std::endl;
  }
  else
    std::cout << "No students from file." << std::endl;
}

/*
******************************************************
* Function: load_teachers
* return: none
* parameters: none
*
* Description:
* Loads Teacher objects from the file identified by
* teachers_file if it exists.
******************************************************
*/
void load_teachers()
{
  std::cout << "Loading teachers...\n";
  Teacher teacher;
  std::ifstream infile {teachers_file};                                 // Open the file to read it
  if (infile.is_open())                                                 // If it is open...
  {                                                                     // ...it exists, so read it
    while (true)
    {
      infile >> teacher;                                                // Read a teacher and...
      if (infile.eof()) break;
      teachers.add(teacher);                                            // ...add the teacher to the group.
    }
    std::cout << "Teachers loaded from file." << std::endl;
    infile.close();
  }
  else
    std::cout << "No teachers from file." << std::endl;
}

/******************************************************
* Function: isFile
* return:  bool
* parameters:  std::ios (base for all stream classes)
*
*  Description:
*  Returns true if the argument is a file input stream.
*  Used to decide when to prompt for stream input.
******************************************************/
bool isFile(std::ios& stream)
{
  return (typeid(stream) == typeid(std::ifstream)) || (typeid(stream) == typeid(std::ofstream)) 
                                                   || (typeid(stream) == typeid(std::fstream));
}

/******************************************************
* Function: notFile
* return:  bool
* parameters:  std::istream
*
*  Description:
*  Returns true if the argument is not a file input stream.
*  Used to decide when to prompt for stream input
******************************************************/
bool notFile(std::ios& in)
{
  return !isFile(in);
}


/******************************************************
* Function: isInteger
* return:  bool
* parameters:  std::string
*
*  Description:
*  Returns true if the argument contains only characters '0' to '9'.
*  Used to verify that a string object represents an integer.
******************************************************/
bool isInteger(string s)
{
  for (char ch : s)
  {
    if (!std::isdigit(ch))
      return false;
  }
  return true;
}

/*
******************************************************
* Function: display_records
* return:  void
* parameters:  none
*
*  Description:
*  Displays all the records of the chosen type.
******************************************************
*/
void display_records()
{
  // Display the display Record System menu
  std::cout << "Choose the set of records to display.\n";
  switch (choose_person_type())
  {
  case 'T':                                    // display all teachers
    std::cout << teachers;
    break;
  case 'S':                                    // display all students
    std::cout << students;
    break;
  }
}

/******************************************************
* Function: choose_person_type
* return:  char
* parameters:  none
*
*  Description:
*  Returns an uppercase character identifying a record type,
*  either 'S' for students ot 'T' for teachers.
******************************************************/

char choose_person_type()
{
  char option {};
  while (true)
  {
    std::cout << "Choose either (S)tudent or (T)eacher: ";
    std::cin >> option;
    option = std::toupper(option);
    if (option == 'T' || option == 'S') return option;
    std::cout << "invalid choice.\n";
  }
}

/* 
******************************************************
* Function: delete_record
* return:  void
* parameters: none
*
* Description:
* Prompts for the surname of the record to be deleted
* then deletes the record from the chosen set.
******************************************************
*/
void delete_record()
{
  string search_name;

  while (true)
  {
    std::cout << "\nEnter the second name of the record you want to delete, or '.' to abort operation: ";
    std::cin >> search_name;
    if (search_name == ".")  return;

    switch (choose_person_type())
    {
    case 'T':
      teachers.remove(search_name);
      break;
    case 'S':
      students.remove(search_name);
    }
  }
}

bool confirm_delete(string s)
{
  char option {};
  std::cout << "Are you sure you want to delete all " << s << " [Y/N]?  ";
  std::cin >> option;
  if (std::toupper(option) == 'Y')
    return true;
  return false;
}

/* 
******************************************************
* Function: delete_all_records
* return:  void
* parameters: none
*
* Description:
* Clears a set of records of a given type, after
*  confirming the user's choice.
******************************************************
*/
void delete_all_records()
{
  string selected;
  bool deleted {false};
  switch (choose_person_type())
  {
  case 'S':
    selected = "students";
    if (confirm_delete(selected))
    {
      students.clear();
      deleted = true;
    }
    break;
  case 'T':
    selected = "teachers";
    if (confirm_delete(selected))
    {
      teachers.clear();
      deleted = true;
    }
    break;
  }
  if (deleted)
    std::cout << "All " << selected << " deleted." << std::endl;
  else
    std::cout << "Deletion aborted." << std::endl;
}

/* 
******************************************************
* Function: add_record
* return:  void
* parameters: none
*
* Description:
* Add a single record of a chosen type, either a Student or a Teacher.
******************************************************
*/


void add_record()
{
  Student student;
  Teacher teacher;
  switch (choose_person_type())
  {
  case 'T':
    // Add a teacher record
    std::cout << std::endl << "Adding Teacher record." << std::endl;
    std::cin >> teacher;
    teachers.add(teacher);
    break;
  case 'S':
    // Add a student record
    std::cout << std::endl << "Adding Student record." << std::endl;
    std::cin >> student;
    students.add(student);
    break;
  }
}


/* 
******************************************************
* Function: find_record
* return:  void
* parameters: none
*
* Description:
* Prompts for a surname and searches the chosen set
* of records for the name. If the record is found
* it is displayed.
******************************************************
*/

void find_record()
{
  string surname;

  // Display the Search Surname Menu
  std::cout << std::endl << "Enter the Surname to Search for." << std::endl;
  std::cin >> surname;
  bool found {false};
  switch (choose_person_type())
  {
  case 'S':
  {
    auto pperson = students.find(surname);
    if (pperson)
    {
      std::cout << *pperson << std::endl;
      found = true;
    }
  }
    break;
  case 'T':
  {
    auto pperson = teachers.find(surname);
    if (pperson)
    {
      std::cout << *pperson << std::endl;
      found = true;
    }
  }
    break;
  }
  if (!found)
    std::cout << surname << " not found." << std::endl;
}

/* 
******************************************************
* Function: save_records 
* return:  void
* parameters: none
*
* Description:
* Save all the records to files.
******************************************************
*/

void save_records()
{
  std::ofstream out {students_file};
  if (!out.is_open())
  {
    std::cerr << "Cannot create output file for students." << std::endl;
    return;
  }
  else
  {
    out << students;
    out.close();
    std::cout << "Student records written to file." << std::endl;
  }

  out.open(teachers_file);
  if (!out.is_open())
  {
    std::cerr << "Cannot create output file for teachers." << std::endl;
    return;
  }
  out << teachers;
  out.close();
  std::cout << "Teacher records written to file." << std::endl;
}
