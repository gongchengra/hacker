# File: os-example-14.py
# Using the os module to run as daemon (Unix)

import os
import time

pid = os.fork()
if pid:
    os._exit(0) # kill original

print "daemon started"
time.sleep(10)
print "daemon terminated"
