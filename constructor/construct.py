# Foundation Package Manager
# constructor
# Developed by Brett. (https://github.com/notronaldmcdonald)

# imports

import random
import getpass
import subprocess

# variables

version = "1.0.0"
name = getpass.getuser() + "?"
ename = getpass.getuser() + "."

# greeting list

greetings = ["How are you today,", "What\'s happening,", "How\'s it hangin\',"]

# begin script

print(random.choice(greetings), name)
print("\nWelcome to FPM Constructor.")
print("Current version:", version)
print("\nThis tool will compress a binary for you.\nIt is recommended you use this tool in your package repo.")
print("\nWhat is the name of the binary file you're packaging? (it is recommended to not use extensions.)")
target = input("Enter the name of the binary: ")
print(f"Is {target} correct?")
answer = input("Enter a response [Y/n]: ")
if answer == "n":
    print("User aborted.")
    exit()
else:
    subprocess.run(["tar", "-czvf", f"{target}.tar.gz", f"{target}"])
    print("Archive created.")
    print("Done.")
print("All good.")
print("\nHave a good day,", ename)
