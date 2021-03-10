# Foundation Package Manager
# Spine Script
# Manages the system installation of FPM.
# Developed by Brett

# imports

import subprocess
import tarfile
import pathlib
import os
from sys import platform

# assign variables

user = os.getlogin()

# begin script

print("\nfpm: starting python process")
print("fpm_spine: checking operating system")
if platform == "linux" or platform == "linux2":
    print("fpm_spine: sys.platform returns GNU/Linux")
elif platform == "darwin":
    print("fpm_spine: sys.platform returns OS X")
elif platform == "win32":
    print("fpm_spine: sys.platform returns Windows")
print("fpm_spine: checking for installation directories...")
if platform == "linux" or platform == "linux2" or platform == "darwin":
    pathlib.Path("/home/%s/.fpm/install" % user).mkdir(parents=True, exist_ok=True)
elif platform == "win32":
    pathlib.Path("C:\\Users\\%s\\.fpm\\install" % user).mkdir(parents=True, exist_ok=True)
print("fpm_spine: getting package (curl)")
if platform == "darwin" or platform == "linux" or platform == "linux2":
    print("fpm_spine: runcmd 'curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs/fpm2_core.tar'")
    subprocess.run(["curl", "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs/fpm2_core.tar", "-o", "/home/%s/.fpm/install/fpm2_core.tar" % user])
elif platform == "win32":
    print("fpm_spine: runcmd 'curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs/fpm2_core.tar'")
    print("fpm_spine: running based on windows filesystem conventions...")
    subprocess.run(["curl", "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs/fpm2_core.tar", "-o", "C:\\Users\\%s\\.fpm\\install\\fpm2_core.tar" % user])
print("fpm_spine: package downloaded.")
print("fpm_spine: unpacking package...")
print("fpm_spine: start tar management.")
print("fpm_spine: determine conventions...")
if platform == "linux" or platform == "linux2" or platform == "darwin":
    pkgtar = tarfile.open("/home/%s/.fpm/install/fpm2_core.tar" % user)
    pkgtar.extractall("/home/%s/.fpm/install" % user)
    pkgtar.close()
elif platform == "win32":
    pkgtar = tarfile.open("C:\\Users\\%s\\.fpm\\install\\fpm2_core.tar" % user)
    pkgtar.extractall("C:\\Users\\%s\\.fpm\\install\\" % user)
    pkgtar.close()
print("fpm_spine: unpacked package.")
print("fpm_spine: all good, passing back to core.")

# end script
