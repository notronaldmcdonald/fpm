// Foundation Package Manager
// A package manager written in C++/Ruby (with a bit of python).
// Developed by Brett. (https://github.com/notronaldmcdonald)

// MIT License

// Copyright (c) 2021 Brett I. <https://github.com/notronaldmcdonald>

/* Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

// header
#include <iostream>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <stdlib.h>

// declare colorization functions
void yellow() {
  system("tput setaf 11");
}
void white() {
  system("tput setaf 15");
}
void red() {
  system("tput setaf 9");
}
void green() {
  system("tput setaf 10");
}
void blue() {
  system("tput setaf 14");
}

using namespace std;
// code starts here
int main( int argc, char *argv[] ) {
// VARIABLES - all of the variables from versions to commands.

  // INFO
    // define the code build running
    // these are mostly to allow checking if code is deemed stable or not before publishing.
    const string buildType = "devel"; // buildType indicates whether this source code is development (devel), pre-release (pre), or stable/release code (rel).
    const string build = "v2.1.0-dev.1"; // build indicates the version number for the release when the code is compiled. however, i also apply it internally to track versioning.
  // INPUT
    string input; // general input string
    int dinput; // documentation browser's input
    string confirm_dinput; // documentation browser confirm
    string hinput; // help browser's input
    string confirm_hinput; // help browser's confirm
  // RANDOM
    int k = 6; // used only to operate the while loop
  // SYSTEM COMMANDS
  const string install = "ruby /usr/local/bin/.fpm_spine_install.rb";
  const string uninstall = "ruby /usr/local/bin/.fpm_spine_uninstall.rb";
  const string search = "ruby /usr/local/bin/.fpm_glasses.rb";
  const string getchangelog = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/CHANGELOG.md -o /tmp/CHANGELOG.md";
  const string readchangelog = "cat /tmp/CHANGELOG.md";
  const string cleanchangelog = "rm -f /tmp/CHANGELOG.md";
  const string getdoc1 = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/README.md";
  const string getdoc2 = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/constructor/README.md";
  const string getdoc3 = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/CHANGELOG.md";
  const string getdoc4 = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/CONTRIBUTING.md";
  const string getdoc5 = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/INSTALL.md";
  const string getdoc6 = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/LICENSE";
  const string getdoc7 = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/src/devel.md";
  const string helpbrowser = "ruby /usr/local/bin/.fpm_spine_help.rb";
  const string debug = "echo \"debug message\""; // this is a developer tool used for testing purposes.
// END OF VARIABLES

  // commands start here

  // documentation browser
  if ( (argc == 2) && (string(argv[1]) == "docs") ) {
    while (k == 6) {
    yellow();
    cout << "\nfpm: documentation";
    white();
      cout << "\n\nThe Foundation Package Manager (build " << build << ")";
      cout << "\n\nWelcome to the Foundation Package Manager documentation browser.";
      cout << "\nThis tool is intended to allow users to access the documentation from the commandline.";
      cout << "\nSelect a documentation resource from the following list:";
      cout << "\n\n1. README";
      cout << "\n2. construct_README";
      cout << "\n3. CHANGELOG";
      cout << "\n4. CONTRIBUTING";
      cout << "\n5. INSTALL";
      cout << "\n6. LICENSE";
      cout << "\n7. devel";
      cout << "\n\nType the number of the documentation file you wish to download: ";
      cout << "\nPress CTRL+C to exit.\n";
      cin >> dinput;
      cout << "\nYou entered: " << dinput;
      cout << "\nIs this correct? [Y/n]\n";
      cin >> confirm_dinput;
      cout << "\nfpm: evaluating...";
      if (confirm_dinput == "n") {
        cout << "\nfpm: user aborted.";
        break;
      }
      else {
        if (dinput == 1) {
          system(getdoc1.c_str());
        }
        else if (dinput == 2) {
          system(getdoc2.c_str());
        }
        else if (dinput == 3) {
          system(getdoc3.c_str());
        }
        else if  (dinput == 4) {
          system(getdoc4.c_str());
        }
        else if (dinput == 5) {
          system(getdoc5.c_str());
        }
        else if (dinput == 6) {
          system(getdoc6.c_str());
        }
        else if (dinput == 7) {
          system(getdoc7.c_str());
        }
        else {
          cout << "\nfpm: invalid";
          red();
          cout << "\nfpm: fatal: unknown documentation.";
          white();
          break;
        }
      }
    }
  }
  // version command
  if ( (argc == 2) && (string(argv[1]) == "version") ) {
    yellow();
    cout << "\nfpm: version";
    white();
    cout << "\n\nfpm: the foundation package manager";
    cout << "\nwritten in C++, with components in ruby and python.";
    blue();
    cout << "\nbuild: " << build;
    cout << "\nbuildType: " << buildType;
    white();
    cout << "\nIf the buildType string is 'devel' or 'pre', you are dealing with non-release code. (or i forgot to fix the tag before releasing)";
  }
  // search command
  if ( (argc == 2) && (string(argv[1]) == "search") ) {
    yellow();
    cout << "\nfpm: search";
    white();
    system(search.c_str());
  }
  // changelog command
  if ( (argc == 2) && (string(argv[1]) == "changelog") ) {
    yellow();
    cout << "\nfpm: changelog";
    blue();
    cout << "\nfpm: changelog: download";
    white();
    system(getchangelog.c_str());
    yellow();
    cout << "\nfpm: changelog";
    white();
    cout << "\nfpm: changelog: read";
    system(readchangelog.c_str());
    cout << "\nfpm: changelog";
    cout << "\nfpm: cleaning up";
    system(cleanchangelog.c_str());
    green();
    cout << "\nfpm: exit";
    white();
  }
  // help browser
  else if ( (argc == 2) && (string(argv[1]) == "help") ) {
    cout << "\nfpm: help";
    cout << "\nfpm: runscript";
    system(helpbrowser.c_str());
    cout << "\nfpm: exit";
  }
  // syntax error
  if ( ( argc != 3 ) && (string(argv[1]) != "changelog") && (string(argv[1]) != "search") && (string(argv[1]) != "version") && (string(argv[1]) != "help") ) {
    red();
    cout << "\nerror: invalid syntax. usage: " << argv[0] << " <operation> <target>";
  }
  else {
    cout << "\nfpm: all good\n\n";
  }
  // print the fpm help
  if ( (argc == 3) && (string(argv[1]) == "help") && (string(argv[2]) == "fpm") ) {
    yellow();
    cout << "fpm: help";
    white();
    cout << "\n\ninstall: install a program";
    cout << "\nuninstall: uninstall a program";
    cout << "\nsearch: search repositories for a program";
    cout << "\nversion: display fpm version + subscript versions.";
    cout << "\nchangelog: get the CHANGELOG.md file from upstream/core.";
    cout << "\ndocs: display the documentation browser.";
    cout << "\nhelp: display the help documentation browser.";
  }
  // install package
  if ( (argc == 3) && (string(argv[1]) == "install") ) {
    yellow();
    cout << "\nfpm: install";
    white();
    cout << "\n\nfpm: running search function";
    cout << "\nfpm: search: write target to tempfile";
    std::string target;
    target.append(string(argv[2]));
    ofstream targetfile;
    targetfile.open ("/tmp/.target");
    targetfile << target;
    targetfile.close();
    yellow();
    cout << "\nfpm: search: switch to ruby";
    white();
    system(install.c_str());
    cout << "\nfpm: search: ruby";
    cout << "\nfpm: install: done";
    green();
    cout << "\nfpm: exit";
    white();
  }
  // uninstall package
  if ( (argc == 3) && (string(argv[1]) == "uninstall") ) {
    yellow();
    cout << "\nfpm: uninstall";
    std::string target;
    target.append(string(argv[2]));
    ofstream targetfile;
    targetfile.open ("/tmp/.target.txt");
    targetfile << target;
    targetfile.close();
    cout << "\nfpm: run spine script";
    white();
    system(uninstall.c_str());
  }
}

// code ends here
