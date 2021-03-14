# FPM constructor
### A quick package assembly tool.

Constructor is a tool used to package a binary into the FPM format.

The tool is very intuitive. There isn't much to document, but I will do what I can.

Upon running the tool, you'll get a greeting, the current version, and a prompt for the binary you're packaging.
Enter the name of the binary. You'll then receive a confirmation prompt. Typing "n" will abort. Otherwise, it'll continue.
It creates a tarball with your binary. You can then add the entry to your repository's `index.txt` file, or submit it to somebody else's
repository.

###### The tool is written in Python and is a subcomponent of the Foundation Package Manager. As such, it falls under the MIT [License](../LICENSE).
