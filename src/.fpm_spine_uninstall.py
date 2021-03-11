# Foundation Package Manager
# spine_uninstall
# Developed by Brett. (https://github.com/notronaldmcdonald)

# imports

import subprocess
import pathlib
from pathlib import Path
import os
import sys
from sys import platform

# some variables

home = str(Path.home())

# begin script

exec(open('.choice.txt').read())
print("fpm_spine: finding out what you chose...")
if choice == "n":
    print("fpm_spine: running non-interactively")
    exec(open('.target.txt').read())
    print("fpm_spine: looking up package in pkglist...")
    if platform != "win32":
        subprocess.run(["cat", f"{home}/.fpm/pkgs/pkglist.txt", "|", "grep", "-w", f"{target}", ">", ".output.tmp"])
        validitycheck = os.path.getsize(".output.tmp")
        if validitycheck == 0:
            print("fpm_spine: unable to find package")
            print("fpm_spine: a fatal error occurred. exiting.")
            sys.exit()
        else:
            print("fpm_spine: lookup successful.")
            print("fpm_spine: removing package")
            subprocess.run(["rm", "-f", f"{home}/.fpm/pkgs/{target}*"])
            print("fpm_spine: done.")
        print("fpm_spine: end task")
    else:
        subprocess.run(["type", f"{home}\\.fpm\\pkgs\\pkglist.txt", "|", "find", f"{target}", ">", ".output.tmp"])
        validitycheck = os.path.getsize(".output.tmp")
        if validitycheck == 0:
            print("fpm_spine: unable to find package")
            print("fpm_spine: a fatal error occurred. exiting.")
            sys.exit()
        else:
            print("fpm_spine: lookup successful")
            print("fpm_spine: removing package")
            subprocess.run(["del", "/f", f"(home/.fpm/pkgs/{target}*)"])
            print("fpm_spine: done.")
        print("fpm_spine: end task")
else:
    print("fpm_spine: uninstall")
    print("\nfpm_spine: list packages")
    if platform != "win32":
        subprocess.run(["cat", f"{home}/.fpm/pkgs/pkglist.txt"])
    else:
        subprocess.run(["type", f"{home}\\.fpm\\pkgs\\pkglist.txt"])
    print("Welcome to the Uninstall Tool.")
    print("Choose a package from the list to remove.")
    target = input("Enter your selection: ")
    print("fpm: uninstall: attempt removal...")
    if platform != "win32":
        print("fpm: uninstall: unix")
        subprocess.run(["rm", "-f", f"{home}/.fpm/pkgs/{target}*"])
        print("fpm: uninstall: if package exists, should be removed.")
    else:
        print("fpm: uninstall: windows")
        subprocess.run(["del", "/f", f"{home}\\.fpm\\pkgs\\{target}*"])
        print("fpm: uninstall: if package exists, should be removed.")
    print("fpm: uninstall: done.")
print("fpm_spine: cleanup")
if platform != "win32":
    subprocess.run("rm", "-f", ".output.tmp")
    subprocess.run("rm", "-f", ".choice.txt")
    subprocess.run("rm", "-f", ".target.txt")
else:
    subprocess.run("del", "/f", ".output.tmp")
    subprocess.run("del", "/f", ".choice.txt")
    subprocess.run("del", "/f", ".target.txt")
print("fpm_spine: done")
