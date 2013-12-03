# File: os-exec-example-1.py
# Using the os module to start a new process

import os
import sys

program = "python"
arguments = ["hello.py"]

print os.execvp(program, (program,) +  tuple(arguments))
print "goodbye"

