# FPM Package
# Package files from the file stem.
# The quick-run version of the script used by running 'fpm package'. packages files around a .stem file indiscriminately.
# Developed by Brett. (https://github.com/notronaldmcdonald)

# import

import subprocess
import tarfile
import pathlib
import os
import os.path
import glob
from sys import platform

# variables

user = os.getlogin()

# begin script

print("fpm: package")
print("\npackage_head: searching for .stem file...")
if os.path.isfile(".stem"):
    print("package_head: stem exists. package all.")
    tar = tarfile.open("package.tar.gz", "w:gz")
    for name in glob.glob('*'):
        tar.add(name)
    tar.close()
    print("fpm: packaged")
else:
    print("package_head: fatal: no stem")
print("fpm: exit")
