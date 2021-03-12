// Foundation Package Manager
// A package manager written in C++/Ruby (with a bit of python).
// Developed by Brett. (https://github.com/notronaldmcdonald)

// MIT License

//Copyright (c) 2021 Brett I. <https://github.com/notronaldmcdonald>

/*Permission is hereby granted, free of charge, to any person obtaining a copy
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
SOFTWARE.*/

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
  const string build = "v1.9.14";
  // variables here
  string input;
  // system commands
  //const string installfpmcommand = "python /usr/local/bin/.fpm_spine_install_fpm.py";
  const string install = "ruby /usr/local/bin/.fpm_spine_install.rb";
  const string uninstall = "python /usr/local/bin/.fpm_spine_uninstall.py";
  const string search = "ruby /usr/local/bin/.fpm_glasses.rb";
  // obsolete - const string getindex = "curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs/index.txt -o .index.tmp";

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
    cout << "\nversion: display fpm version + subscript versions.";
  }
  // tell the user where help files are
  else if ( (argc == 3) && (string(argv[1]) != "install") && (string(argv[2]) != "fpm") && (string(argv[1]) == "help") ) {
    cout << "fpm: help";
    cout << "\n\nhelp documentation for every package installed (that has help documentation) is located in a ~/.fpm/help/<program>_help.txt file";
    cout << "\n(on windows, that's in your user folder.)";
  }
  // install fpm - disabled by default
  //if ( (argc == 3) && (string(argv[1]) == "install") && (string(argv[2]) == "fpm") ) {
    //cout << "fpm: install";
    //cout << "\n\n------------------------------------------";
    //cout << "\n found package 'fpm' at core/pkgs/fpm.tar";
    //cout << "\n\ninstall package 'fpm' from core/fpm? [Y/n]\n";
    //cout << "\n------------------------------------------\n";
    //cout << "Enter your command: ";
    //cin >> input;
    //cout << "\nfpm: install: user input: " << input;
    //if ( (string(input) == "n") ) {
      //cout << "\nfpm: install: user refused install.";
    //}
    //else {
      //cout << "\nfpm: install: user accepted install.";
      //cout << "\nfpm: install: installing package 'fpm' from core/fpm...";
      //system(installfpmcommand.c_str());
      //cout << "\nfpm: install: returning from spine";
      //cout << "\nfpm: finishing install of self";
      //cout << "\nfpm: package 'fpm' installed. add ~/.fpm/pkgs to your PATH if you haven't done so.";
    //}
  // version check
  if ( (argc == 3) && (string(argv[1]) == "version") ) {
    cout << "\nfpm: version";
    cout << "\n\nfpm: the foundation package manager";
    cout << "\nwritten in C++, with components in ruby and python.";
    cout << "\nbuild: " << build;
    cout << "\n\nfpm_spine: the backbone of fpm";
    cout << "\nwritten in ruby, with uninstall still in python.";
    cout << "\nbuild: " << build;
  }
  // install package
  if ( (argc == 3) && (string(argv[1]) == "install") ) {
    cout << "\nfpm: install";
    cout << "\n\nfpm: running search function";
    cout << "\nfpm: search: write target to tempfile";
    std::string target;
    target.append("\"");
    target.append(string(argv[2]));
    target.append("\"");
    ofstream targetfile;
    targetfile.open ("/tmp/.target");
    targetfile << "target = " << target;
    targetfile.close();
    cout << "\nfpm: search: switch to ruby";
    system(install.c_str());
    cout << "\nfpm: search: ruby";
    cout << "\nfpm: install: done";
    cout << "\nfpm: exit";
  }
  // uninstall package
  if ( (argc == 3) && (string(argv[1]) == "uninstall") ) {
    cout << "\nfpm: uninstall";
    cout << "\nasking for input";
    cout << "\nfpm: run interactively? [Y/n] ";
    cin >> input;
    cout << "\nfpm: " << input;
    std::string target;
    target.append("'");
    target.append(string(argv[2]));
    target.append("'");
    ofstream targetfile;
    targetfile.open (".target.txt");
    targetfile << "target=" << target;
    targetfile.close();
    std::string choice;
    choice.append("'");
    choice.append(input);
    choice.append("'");
    ofstream choicefile;
    choicefile.open (".choice.txt");
    choicefile << "choice=" << choice;
    choicefile.close();
    cout << "\nfpm: run spine script";
    system(uninstall.c_str());
  }
  // search
  if ( (argc == 3) && (string(argv[1]) == "search") ) {
    cout << "\nfpm: search";
    std::string query;
    query.append("'");
    query.append(string(argv[2]));
    query.append("'");
    system(search.c_str());
  }
}

// code ends here
