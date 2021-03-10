// header
#include <iostream>
#include <string.h>
#include <cmath>
#include <fstream>
#include <cstdio>

using namespace std;
// code starts here
int main( int argc, char *argv[] ) {
  // define the code build running
  const string build = "v1devel";
  // variables here
  string input;
  string installdir = "/home/bean/.fpm/install";
  string packagedir = "/home/bean/.fpm/pkgs";
  // system commands
  const string installfpmcommand = "./.fpm_spine_install_fpm.py";
  const string fpminstallp2 = "cp /home/bean/.fpm/install/fpm2_core /home/bean/.fpm/pkgs/fpm"
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
      cout << "\nfpm: install: returning from spine"
      cout << "\nfpm: install: placing files in install directories..."
      cout << "\n\nfpm: operating system check"
      #ifdef __linux__
        // linux code
        cout << "\nfpm: running on linux"
        cout << "\nfpm: return to install"
        cout << "\nfpm: install"
        char text[255];
        FILE *name;
        name = popen("whoami", "r");
        fgets(text, sizeof(text), name);
        cout << "\nusername: " << text;
        cout << "\nfpm: install: substitute bean";
        installdir.replace(7,4,text);
        packagedir.replace(7,4,text);
      #elif _WIN32
        // win32 code
    }
  }
  cout << "\n\nfpm: done!";
}
// code ends here
