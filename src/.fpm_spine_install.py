# Foundation Package Manager
# spine_install
# Developed by Brett. (https://github.com/notronaldmcdonald)

# imports

import subprocess
import tarfile
import pathlib
from pathlib import Path
import os
import sys
import string
from string import Template
from sys import platform

# some variables

user = os.getlogin()
core = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs"
home = str(Path.home())

# USER - define your package sources by adding an additional dictionary entry. you can simply add additional 'curl' lines to the download portion of the script.
# Replace the selection at the end of the new curl line with your source name. (i.e. '[...] % core' > '[...] % userrepo')

# begin script

print("fpm: starting python script...")
exec(open('.target.txt').read())
print("fpm_spine: reading")
print("fpm_spine: operating system check")
if platform != "win32":
    print("fpm_spine: unix")
    print("fpm_spine: try to get package")
    try:
        # USER - this is where downloading happens. copy-paste the curl line and replace 'core' with the repo you added to the dictionary.
        confirmation = input("Continue? [Y/n] ")
        if confirmation == "n" or confirmation == "N":
            print("fpm_spine: aborted by user")
            sys.exit()
        else:
            # the aforementioned curl line is below
            subprocess.run(["curl", f"{core}/%s.tar.gz", "-o", f"{home}/.fpm/install/%s.tar.gz" % target])
            # the aforementioned curl line is above
            print("fpm_spine: unpacking")
            subprocess.run(["tar", "-xvzf", f"{home}/.fpm/install/%s.tar.gz" % target])
            exec(open("{home}/.fpm/install/fpkgd").read())
            print("fpm_spine: determine the binary")
            subprocess.run(["cp", f"{home}/.fpm/install/%s", f"{home}/.fpm/pkgs/%s" % base])
            print("fpm_spine: binary should be moved")
    except:
        print("fpm_spine: unknown exception occurred.")
    finally:
        print("fpm_spine: done that")
    print("fpm_spine: cleaning up now")
    subprocess.run(["rm", "-f", f"{home}/.fpm/install/*"])
    subprocess.run(["rm", "-f", ".target.txt"])
    print("fpm_spine: finished cleanup")
else:
    print("fpm_spine: windows")
    print("fpm_spine: try to get package")
    try:
        confirmation = input("Continue? [Y/n] ")
        if confirmation == "n" or confirmation == "N":
            print("fpm_spine: aborted by user")
            sys.exit()
        else:
            # same as the *nix section
            subprocess.run(["curl", f"{core}/%s.tar.gz", "-o", f"{home}\\.fpm\\install\\%s.tar.gz" % target])
            print("fpm_spine: unpacking")
            subprocess.run(["tar", "-xvzf", f"{home}\\.fpm\\install\\%s.tar.gz" % target])
            exec(open(f"{home}\\.fpm\\install\\fpkgd").read())
            print("fpm_spine: determine the binary")
            subprocess.run(["copy", f"{home}\\.fpm\\install\\%s", f"{home}\\.fpm\\pkgs\\%s" % base])
            print("fpm_spine: binary should be moved")
    except:
        print("fpm_spine: unknown exception occurred.")
    finally:
        print("fpm_spine: done that")
    print("fpm_spine: cleaning up now")
    subprocess.run(["del", "/f", f"{home}\\.fpm\\install\\*"])
    subprocess.run(["del", "/f", ".target.txt"])
print("fpm_spine: exit python")
