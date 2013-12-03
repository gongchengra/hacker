# File: os-example-5.py
# Using the os module to list the files in a directory
import os

for file in os.listdir("samples"):
    print file

