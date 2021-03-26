# Developer Docs: Source Code
#### A guide to the source code files.

### So, what exactly is here?

This is the repository's **src** directory. It contains the source code for all versions from version 1.9.9 onwards.
FPM is made up of a combination of scripts and code. The languages used in the project are **C++**, **Ruby**, and **Python**.
The source files are:

**fpm2.cpp** - The \*NIX version of FPM. This is the core component. This is what the user interacts with directly. It is written in **C++**.

**.fpm_spine_\*.rb** - The install/uninstall/help scripts. They are written in **Ruby**, and they require the gem 'colorize'.

**.fpm_glasses.rb** - The interactive search script. It is written in **Ruby**, and requires the gem 'colorize'.

**.installation/fpm2_install_head.cpp** - The core install program. Allows the user to install for \*NIX operating systems. It is written in **C++**.

**.installation/install_nix.rb** - Installs for \*NIX systems. Uses 'curl' to fetch the latest versions of the scripts and the latest compiled binary.

### So, what can I do with these?

The software is licensed with the [MIT License](../LICENSE). This means that you can do whatever you want, provided you maintain copyright notices where applicable. It also means that it comes with no warranty. If you like to tinker, or want to contribute code, I ask that you mark your code with a heading that includes your name and either your email or a link to your GitHub/other service you can be reached by. This is to make sure (in the terms of contributing) that you can be reached to fix your own code, as well as to allow you to be given credit where due.

### How do I do things with this?

There isn't any style requirement. If you're contributing, I'd like to be able to read it, however I can take time to figure out. Naturally, it'd be good if you knew C++, Ruby, or Python, as those are the three regular languages in play. However, you're welcome to contribute in whatever language you like. Of course, if you aren't contributing, you can do literally anything. **There is no restriction on what you can do, you just need to preserve the original copyright notices.**
