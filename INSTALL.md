# FPM Installation
###### A guide on installing my package manager.

### How?

Simple: Download the latest release's `install_scripts.zip` archive. The archive includes a compiled C++ program for you to interact with,
as well as the pure install scripts written in ruby. This is the easiest way to install the software.

Build from source: Download the source code archive from the latest release. This is to ensure you're still getting working code.

###### Build from source steps:

1. Download the source code from the latest release. If you wish, you can check for the latest pre-releases as well.
2. Unpack the source code archive. (on linux, this is done with the command `$ tar -xzvf <archive>.tar.gz`. On Windows, this can be done with your archive management tool of choice.)
3. Move the scripts where they need to go. Move all `.rb` files to `/usr/local/bin/` (linux) or to `C:\Program Files (x86)\foundationpm\` (windows).
4. Compile the C++ executable. On Linux, run `$ g++ fpm2.cpp`. On Windows, use your C++ compiler of choice.
5. Move the C++ executable to `/usr/local/bin/` (linux) or `C:\Program Files (x86)\foundationpm\` (windows) under the name `fpm`.
