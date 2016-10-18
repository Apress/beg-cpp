// Exercise 4.3 Outputting the binary code for a letter.
/******************************************************************************************
 * The program is fairly simple. The cctype functions make determining upper or lower     *
 * case easy. Finding out if it's a vowel is also easy with a switch. Getting the binary  *
 * code needs a little thought.                                                           * 
 * Each of the masks selects a different bit of the ch variable.                          * 
 * If the bit is '1', the expression will be non-zero, which is converted to Boolean true.*
 * If it's '0', the whole expression will be zero, or Boolean false.                      *
 * Ones and zeros are therefore output as appropriate.                                    *
 ******************************************************************************************/
#include <iostream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;

int main() {
  char ch = 0;
  cout << "Enter a letter: ";
  cin >> ch;

  if(!std::isalpha(ch)) {
    cout << "That's not a letter!" << endl;
    return 1;
  }

  // Determine upper or lower case.
  cout << "\'" << ch << "\' is " << (std::islower(ch) ? "lowercase.":"uppercase.") << endl;

  // Determine whether it is a vowel or a consonant.
  cout << "\'" << ch << "\' is a ";
  switch(std::tolower(ch)) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      cout << "vowel.";
      break;
    default:
      cout << "consonant.";
      break;
  }

  // Output the character code as binary
  cout << endl << "The binary code for \'" << ch << "\' is "
       << ((ch & 0x80) ? 1 : 0) << ((ch & 0x40) ? 1 : 0)
       << ((ch & 0x20) ? 1 : 0) << ((ch & 0x10) ? 1 : 0)
       << ((ch & 0x08) ? 1 : 0) << ((ch & 0x04) ? 1 : 0)
       << ((ch & 0x02) ? 1 : 0) << ((ch & 0x01) ? 1 : 0)
       << endl;

  return 0;
}