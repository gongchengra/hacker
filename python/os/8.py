# File: os-example-8.py
# Using the os module to run an operating system command

import os

if os.name == "nt":
    command = "dir"
else:
    command = "ls -l"

os.system(command)

