# File: os-example-7.py
# Using the os module to create and remove directories

import os

os.mkdir("test")
os.rmdir("test")

os.rmdir("samples") # this will fail

