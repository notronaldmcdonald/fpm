// FPM 2.0.0
// Installation Tool
// Developed by Brett. (https://github.com/notronaldmcdonald)

// header
#include <iostream>
#include <string.h>

using namespace std;
// code starts here
int main() {
  /* commands - get home dir */ string home = getenv("HOME");
  const string wininstall = "ruby install_win.rb";
  const string nixinstall = "ruby install_nix.rb";
  const string installdep = "gem install colorize";
  const string installdep2 = "gem install fileutils";
  string createdirs = "mkdir " + home + "/.fpm && mkdir " + home + "/.fpm/install && mkdir " + home + "/.fpm/pkgs && mkdir " + home + "/.fpm/pkgs/help"
  // install function
  function installme() {
    cout << "\nBeginning installation...";
    cout << "\nInstalling ruby dependencies...";
    system(installdep.c_str());
    cout << "\nDependency 'colorize' installed.";
    system(installdep2.c_str());
    cout << "\nDependency 'fileutils' installed.";
    cout << "\nGetting remote files...";
    system(nixinstall.c_str());
    cout << "\nCreating directories...";
    system(createdirs.c_str());
    cout << "\nDone!"
  }

  // variables
  string input;
  // ask for operating system
  cout << "\nReady to install? \n[1.] Yes\n2. No";
  cout << "\nYour response: ";
  cin >> input;
  switch (input) {
    case 1:
      installme
      break;
    case 2:
  }
}
