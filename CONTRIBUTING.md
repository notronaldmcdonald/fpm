# Making contributions

If you're a stranger who just came across this project and wants to submit something, there are a few rules to abide by.

**Submitting package manager code**

* Mark your code with a heading to indicate you wrote said code. This is so issues caused by a piece of code can be reported to the original dev.

* The package manager uses C++ code and Ruby/Python scripts. If you want to submit something that's in a different language, make sure that you've adjusted the rest of the project code to fit it.

* Name your commits clearly, and put details in the description.

**Submit a package**

* Package format is .tar.gz

* All kinds of packages are allowed.

* Your package name must match the binary inside.

* If you wish, include help documentation with your package. These go in /pkgs/help on the remote.
  * Use the same name for the help file as your package.
* All packages should contain a ruby script to tell fpm what to do. See pkgs/index/primefinder.construct.rb for a reference

* This script should be named `<package name>.construct.rb`.

* At the very least, your script needs an `install` function.

* The `construct` tool can generate a basic install function, including dependency support.

**General**

* Make your pull requests against the 'live' branch.
