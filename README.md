# The Foundation Package Manager
## fpm project

I'm bored, and have a whole project going, so
I figured I'd create a package manager.

## Map around the project.

**Branches**

core branch - The release branch of the project.
Tested to be working.

live branch - The working branch of the project.
Not fully tested, script is typically fresh off the griddle.

**Directories**

fpm/ - the source code directory

fpm/constructor/ - the details for creating a package.

fpm/src - source code directory for FPM2.

fpm/.bin - precompiled binary files

## Support Table
What versions are currently supported for fixes, and compatibility packages made available?

------------------------------------
| Version | Support | Latest Build |
|---------|---------|--------------|
| 1.9.14+ | Yes     | 03/13/2021   |
| 1.2.x   | Yes     | 03/11/2021   |
| 1.1.x   | No      | 03/08/2021   |
| 1.0.x   | No      | 03/07/2021   |
| 0.1.x   | No      | 03/10/2021   |

## Usage
Want to use the package manager? Here's a guide on how:

#### Overview
Syntax: fpm <command> <target>

###### Commands
* **install** - Install a package from a remote repository. The user can modify the install script to add their own software repositories.

* **uninstall** - Uninstall an installed package. This removes the binary from the user packages folder.

* **search** - Query a remote database for a package. By default, the `core` repo is queried. (This is interactive. Thus, the target parameter doesn't actually matter, but it still is necessary due to the way the program was written.)

* **version** - With any argument, gets the current version of FPM running.

* **changelog** - With any argument, fetches the [CHANGELOG.md](fpm/core/CHANGELOG.md) file and prints it to the user.

* **help** - Displays FPM help with the target 'fpm', or tells the user where the helpfiles directory is.
