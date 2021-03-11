# Foundation Package Manager
# spine_install
# Developed by Brett. (https://github.com/notronaldmcdonald)

# imports

import subprocess
import tarfile
import pathlib
import os
import sys
from sys import platform

# some variables

internal_index = {'user': os.getlogin(), 'core': "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs"}

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
            subprocess.run(["curl", "{internal_index['core']}/%s.tar.gz", "-o", "/home/{internal_index['user']}/.fpm/install/%s.tar.gz" % target])
            # the aforementioned curl line is above
            print("fpm_spine: unpacking")
            pkgtar = tarfile.open("/home/{internal_index['user']}/.fpm/install/%s.tar.gz" % target)
            pkgtar.extractall("/home/{internal_index['user']}/.fpm/install/")
            pkgtar.close()
            exec(open("/home/{internal_index['user']}/.fpm/install/fpkgd").read())
            print("fpm_spine: determine the binary")
            subprocess.run(["cp", "/home/{internal_index['user']}/.fpm/install/%s", "/home/{internal_index['user']}/.fpm/pkgs/%s" % base])
            print("fpm_spine: binary should be moved")
    except:
        print("fpm_spine: unknown exception occurred.")
    finally:
        print("fpm_spine: done that")
    print("fpm_spine: cleaning up now")
    subprocess.run(["rm", "-f", "/home/{internal_index}['user']/.fpm/install/*"])
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
            subprocess.run(["curl", "{internal_index['core']}/%s.tar.gz", "-o", "C:\\Users\\{internal_index['user']}\\.fpm\\install\\%s.tar.gz" % target])
            print("fpm_spine: unpacking")
            pkgtar = tarfile.open("C:\\Users\\{internal_index['user']}\\.fpm\\install\\%s.tar.gz" % target)
            pkgtar.extractall("C:\\Users\\{internal_index['user']}\\.fpm\\install")
            pkgtar.close()
            exec(open("C:\\Users\\{internal_index['user']}\\.fpm\\install\\fpkgd").read())
            print("fpm_spine: determine the binary")
            subprocess.run(["copy", "C:\\Users\\{internal_index['user']}\\.fpm\\install\\%s", "C:\\Users\\{internal_index['user']}\\.fpm\\pkgs\\%s" % base])
            print("fpm_spine: binary should be moved")
    except:
        print("fpm_spine: unknown exception occurred.")
    finally:
        print("fpm_spine: done that")
    print("fpm_spine: cleaning up now")
    subprocess.run(["del", "/f", "C:\\Users\\{internal_index['user']}\\.fpm\\install\\*"])
print("fpm_spine: exit python")
