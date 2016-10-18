// Exercise 17.4a Removing surplus spaces from a stream.
#include <iostream>
#include <fstream>
#include <string>
using std::string;

// Program to remove surplus spaces from a stream
// We must treat the standard input streams as a special case.
// Because cin has no end of file, so we must determine end of input differently.

// Function to copy one stream to another removing surplus spaces
void copy(std::istream& in, std::ostream& out, char end = ' ')
{
  char ch {};
  bool gotSpace {false};        // True for first space in a sequence

  while(in.get(ch))
  {
    if(end != ' ' && end == ch) // Check for end on cin
      break;
    if(ch==' ')
      if(gotSpace)
        continue;
      else
        gotSpace= true;
    else
      gotSpace = false;
      out.put(ch);
  }
}


// Requires two command line arguments identifying the input and output streams
// First argument is cin or the name and path of the input file
// Second argument is cout or the name and path of the output file
int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    std::cout << "This program requires two command line arguments."
              << "\nThe first command line argument is the input file name and path, or cin."
              << "\nThe second is the output file name and path, or cout.\n";
    exit(1);
  }

  string in {argv[1]};
  string out {argv[2]};
  std::cout << "Reading from " << in << " and writing to " << out << std::endl;

//  std::cout << "Reading from " << argv[1] << " and writing to " << argv[2] << std::endl;

  bool kbd {in == "cin" || in == "std::cin"};         // Standard input stream indicator
  bool scrn {out == "cout" || out == "std::cout"};    // Standard output stream indicator
  char end {};                                        // Indicates end of input on cin;
  if(kbd)
  {
    std::cout << "Enter the character you want to indicate end of input: ";
    std::cin >> end;
    if(scrn)
      copy(std::cin, std::cout, end);
    else {
      std::ofstream outFile {out};
      if(!outFile)
      {
        std::cerr << "Failed to open output file. Program terminated.\n";
        exit(1);
      }
      copy(std::cin, outFile, end);
    }
  }
  else
  {
    std::ifstream inFile {in};
    if(!inFile)
    {
      std::cerr << "Failed to open input file. Program terminated.\n";
      exit(1);
    }
    if(scrn)
      copy(inFile, std::cout);
    else
    {
      std::ofstream outFile {out};
      if(!outFile)
      {
        std::cerr << "Failed to open output file. Program terminated.\n";
        exit(1);
      }
      copy(inFile, outFile);
    }
  }
  std::cout << "\n Stream copy complete." << std::endl;
}