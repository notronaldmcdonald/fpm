// FPM 2.0.0
// Installation Tool
// Developed by Brett. (https://github.com/notronaldmcdonald)

// header
#include <iostream>
#include <string.h>

using namespace std;
void installme() {
  string home = getenv("HOME");
  string createdirs = "mkdir " + home + "/.fpm && mkdir " + home + "/.fpm/install && mkdir " + home + "/.fpm/pkgs && mkdir " + home + "/.fpm/pkgs/help";
  cout << "\nBeginning installation...";
  cout << "\nInstalling ruby dependencies...";
  system("gem install colorize");
  cout << "\nDependency 'colorize' installed.";
  system("gem install fileutils");
  cout << "\nDependency 'fileutils' installed.";
  cout << "\nGetting remote files...";
  system("ruby install_nix.rb");
  cout << "\nCreating directories...";
  system(createdirs.c_str());
  cout << "\nDone!";
}
// code starts here
int main() {
  /* commands - get home dir */
  int input;
  // ask for operating system
  cout << "\nReady to install? \n[1.] Yes\n2. No";
  cout << "\nYour response: ";
  cin >> input;
  switch (input) {
    case 1:
      installme();
      break;
    case 2:
      cout << "\nOkay, cancelling...";
      return 1;
      break;
  }
}
