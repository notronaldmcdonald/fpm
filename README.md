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

fpm/src - source code directory for C++ code.

**Files**

fpkg-stem - the file that denotes that everything around it is a
package component.

fpkgd - package details. denotes what type, version, and permission needs a script has.

fpkgdeps - dependency list.

release-info - information about the release.

## Support Table
What versions are currently supported for fixes, and compatibility packages made available?

---------------------
| Version | Support |
|---------|---------|
| 1.1.x   | Yes     |
| 1.0.x   | No      |
| 0.1.x   | dev     |
