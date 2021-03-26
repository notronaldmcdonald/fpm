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
    const string ver [2] = {"pre", "v2.2.0.pre.1"}; // version data array
  // INPUT
    int dinput; // documentation browser's input
    string inputs [5]; // inputs array (excl. dinput)
  // RANDOM
    bool doLoop = 1; // used only to operate the while loop
  // SYSTEM COMMANDS
  const string cmds[15] = {
    "ruby /usr/local/bin/.fpm_spine_install.rb", // 0
    "ruby /usr/local/bin/.fpm_spine_uninstall.rb", // 1
    "ruby /usr/local/bin/.fpm_glasses.rb", // 2
    "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/CHANGELOG.md -o /tmp/CHANGELOG.md", // 3
    "cat /tmp/CHANGELOG.md", // 4
    "rm -f /tmp/CHANGELOG.md", // 5
    "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/README.md", // 6
    "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/constructor/README.md", // 7
    "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/CHANGELOG.md", // 8
    "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/CONTRIBUTING.md", // 9
    "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/INSTALL.md", // 10
    "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/LICENSE", // 11
    "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/src/devel.md", // 12
    "ruby /usr/local/bin/.fpm_spine_help.rb", // 13
    "echo \"debug message\"" // 14
    // end of array
  };
// END OF VARIABLES

  // commands start here

  // eggman integration commands
  if ( (argc == 4) && (string(argv[1]) == "-e") ) {
    // execute eggman commands
    if (string(argv[2]) == "install") {
      cout << "\nfpm: run eggman install " << argv[3];
      string eggcmd = string("eggman install ") + argv[3];
      system(eggcmd.c_str());
    }
    else if (string(argv[2]) == "uninstall") {
      cout << "\nfpm: run eggman remove " << argv[3];
      string eggcmd = string("eggman remove ") + argv[3];
      system(eggcmd.c_str());
    }
    else {
      cout << "\nerror: invalid eggman command";
    }
  }

  // documentation browser
  if ( (argc == 2) && (string(argv[1]) == "docs") ) {
    while (doLoop == 1) {
    yellow();
    cout << "\nfpm: documentation";
    white();
      cout << "\n\nThe Foundation Package Manager (build " << ver[1] << ")";
      cout << "\n\nWelcome to the Foundation Package Manager documentation browser.";
      cout << "\nThis tool is intended to allow users to access the documentation from the commandline.";
      cout << "\nSelect a documentation resource from the following list:";
      cout << "\n\n1. README";
      // cout << "\n2. construct_README";
      cout << "\n2. CHANGELOG";
      cout << "\n3. CONTRIBUTING";
      cout << "\n4. INSTALL";
      cout << "\n5. LICENSE";
      cout << "\n6. devel";
      cout << "\n\nType the number of the documentation file you wish to download: ";
      cout << "\nPress CTRL+C to exit.\n";
      cin >> dinput;
      cout << "\nYou entered: " << dinput;
      cout << "\nIs this correct? [Y/n]\n";
      cin >> inputs[1];
      cout << "\nfpm: evaluating...";
      if (inputs[1] == "n") {
        cout << "\nfpm: user aborted.";
        break;
      }
      else {
        switch(dinput) {
          case 1:
            system(cmds[6].c_str());
            break;
          case 2:
            system(cmds[7].c_str());
            break;
          case 3:
            system(cmds[8].c_str());
            break;
          case 4:
            system(cmds[9].c_str());
            break;
          case 5:
            system(cmds[10].c_str());
            break;
          case 6:
            system(cmds[11].c_str());
            break;
          case 7:
            system(cmds[12].c_str());
            break;
          default:
            cout << "\nInvalid input.";
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
    cout << "\nwritten in C++, with components in ruby and python.\n";
    blue();
    cout << "\nbuild: " << ver[1];
    cout << "\nbuildType: " << ver[0] << "\n";
    white();
    cout << "\nIf the buildType string is 'devel' or 'pre', you are dealing with non-release code. (or i forgot to fix the tag before releasing)";
  }
  // search command
  if ( (argc == 2) && (string(argv[1]) == "search") ) {
    yellow();
    cout << "\nfpm: search";
    white();
    system(cmds[2].c_str());
  }
  // changelog command
  if ( (argc == 2) && (string(argv[1]) == "changelog") ) {
    yellow();
    cout << "\nfpm: changelog";
    blue();
    cout << "\nfpm: changelog: download";
    white();
    system(cmds[3].c_str());
    yellow();
    cout << "\nfpm: changelog";
    white();
    cout << "\nfpm: changelog: read";
    system(cmds[4].c_str());
    cout << "\nfpm: changelog";
    cout << "\nfpm: cleaning up";
    system(cmds[5].c_str());
    green();
    cout << "\nfpm: exit";
    white();
  }
  // help browser
  else if ( (argc == 2) && (string(argv[1]) == "help") ) {
    cout << "\nfpm: help";
    cout << "\nfpm: runscript";
    system(cmds[13].c_str());
    cout << "\nfpm: exit";
  }
  // syntax error
  if ( ( argc != 3 ) && (string(argv[1]) != "changelog") && (string(argv[1]) != "search") && (string(argv[1]) != "version") && (string(argv[1]) != "help") ) {
    red();
    cout << "\nerror: invalid syntax. usage: " << argv[0] << " [-e] <operation> <target>";
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
    system(cmds[0].c_str());
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
    system(cmds[1].c_str());
  }
}

// code ends here
