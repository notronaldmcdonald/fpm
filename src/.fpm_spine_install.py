# Foundation Package Manager
# spine_install
# Developed by Brett. (https://github.com/notronaldmcdonald)

# imports

import subprocess
import tarfile
import pathlib
import os
from sys import platform

# some variables

user = os.getlogin()

# USER - define your package sources here. you can simply add additional 'curl' lines to the download portion of the script.
# Replace the selection at the end of the new curl line with your source name. (i.e. '[...] % core' > '[...] % userrepo')

core = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs"

# begin script

print("fpm: starting python script...")
exec(open('.target.txt').read())
print("fpm: search: ")
