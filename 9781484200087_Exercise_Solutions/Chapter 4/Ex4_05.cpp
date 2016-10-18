// Exercise 4.5 Dividing a cash amount into quarters, nickels, dimes and cents.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  // Declare the constants
  const int quarter = 25;
  const int dime = 10;
  const int nickel = 5;

  double amount = 0.0;
  cout << endl << "Please enter a cash amount between 0 and 10 dollars: $";
  cin >> amount;
  int amountInCents = 0;

  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int cents = 0;


  if ((amount > 0.0) && (amount <= 10.0)) {
    // Multiply dollar amount by 100 ($1 = 100 cents)
    // We add 0.5 to compensate for errors in binary floating-point representation
    amountInCents = amount * 100.0+0.5;

    // Find the number of quarters
    quarters = amountInCents/quarter;
    amountInCents %= quarter;               // Get the remainder

    // Find the number of dimes
    dimes = amountInCents / dime;
    amountInCents %= dime;                  // Get the remainder

    // Find the number of nickels
    nickels = amountInCents / nickel;
    amountInCents %= nickel;                // Get the remainder

    // Find the number of cents
    cents = amountInCents;                // The remainder is already in cents

    cout << endl 
         << "The dollar value $" << amount << " can be broken down into:"  << endl
         << quarters << " quarter" << ((1 == quarters) ? "," : "s,") << endl
         << dimes    << " dime"    << ((1 == dimes)    ? "," : "s,") << endl
         << nickels  << " nickel"  << ((1 == nickels)  ? "," : "s,") << endl
         << cents    << " cent"    << ((1 == cents)    ? "." : "s.") << endl;
  }
  else
    cout << endl << "You did not enter a dollar amount between 0 and 10." << endl;

  return 0;
}