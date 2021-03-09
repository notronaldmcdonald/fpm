// header
#include <iostream>
#include <string.h>
#include <cmath>
#include <fstream>

using namespace std;
// code starts here
int main( int argc, char *argv[] ) {
  // define the code build running
  const string build = "v1devel";
  // variables here
  string input;
  const string installfpmcommand = "./.fpm_spine_install_fpm.py";
  // process starts here
  // tell the user the syntax is wrong
  if ( argc != 3 ) {
    cout << "\nerror: invalid syntax. usage: " << argv[0] << " <operation> <target>";
  }
  else {
    cout << "fpm: all good\n\n";
  }
  // print the fpm help
  if ( (argc == 3) && (string(argv[1]) == "help") && (string(argv[2]) == "fpm") ) {
    cout << "fpm: help";
    cout << "\n\ninstall: install a program";
    cout << "\nuninstall: uninstall a program";
    cout << "\nsearch: search repositories for a program";
    cout << "\nversion: display version data for a program.";
  }
  // tell the user where help files are
  else if ( (argc == 3) && (string(argv[1]) != "install") && (string(argv[2]) != "fpm") && (string(argv[1]) == "help") ) {
    cout << "fpm: help";
    cout << "\n\nhelp documentation for every package installed (that has help documentation) is located in a ~/.fpm/help/<program>_help.txt file";
    cout << "\n(on windows, that's in your user folder.)";
  }
  // install fpm
  if ( (argc == 3) && (string(argv[1]) == "install") && (string(argv[2]) == "fpm") ) {
    cout << "fpm: install";
    cout << "\n\n------------------------------------------";
    cout << "\n found package 'fpm' at core/pkgs/fpm.tar";
    cout << "\n\ninstall package 'fpm' from core/fpm? [Y/n]\n";
    cout << "\n------------------------------------------\n";
    cout << "Enter your command: ";
    cin >> input;
    cout << "\nfpm: install: user input: " << input;
    if ( (string(input) == "n") ) {
      cout << "\nfpm: install: user refused install.";
    }
    else {
      cout << "\nfpm: install: user accepted install.";
      cout << "\nfpm: install: installing package 'fpm' from core/fpm...";
      system(installfpmcommand.c_str());
    }
  }
  cout << "\n\nfpm: done!";
}
// code ends here
