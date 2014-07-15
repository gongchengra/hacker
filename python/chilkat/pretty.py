#!/usr/bin/python

import sys
#import getopt
import chilkat
xml = chilkat.CkXml()
#xml.LoadXml("chunk_326927.xml")
xml.LoadXml(sys.argv[1])
#print xml.getXml()
#sys.stdout.write(xml.getXml())
f = open(sys.argv[2],'wb')
f.write(xml.getXml())
