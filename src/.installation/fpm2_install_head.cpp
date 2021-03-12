// FPM 2.0.0
// Installation Tool
// Developed by Brett. (https://github.com/notronaldmcdonald)

// header
#include <iostream>
#include <string.h>

using namespace std;
// code starts here
int main() {
  // commands
  const string wininstall = "ruby install_win.rb";
  const string nixinstall = "ruby install_nix.rb";
  // variable
  string input;
  // ask for operating system
  cout << "\nAre you running on Windows or something else? (enter 'windows' if windows, 'else' if else.)";
  cout << "\nYour response: ";
  cin >> input;
  if (input == "windows") {
    system(wininstall.c_str());
  }
  else {
    system(nixinstall.c_str());
  }
  cout << "\ncoolio.";
}
