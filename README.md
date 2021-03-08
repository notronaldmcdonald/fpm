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

fpm/constructor/ - the code and other components for creating a package.

**Files**

fpkg-stem - the file that denotes that everything around it is a
package component.

pkgd - package details. denotes what type, version, and permission needs a script has.
