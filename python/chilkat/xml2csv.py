#!/usr/bin/python

import sys
#import getopt
import csv
import chilkat

stylexml = chilkat.CkXml()
#xml.LoadXml("chunk_326927.xml")
success = stylexml.LoadXml("ahiv_v1.xml")
#success = stylexml.LoadXml(sys.argv[1])
if (success != True):
    print(stylexml.lastErrorText())
    sys.exit()

inputxml = chilkat.CkXml()
success = inputxml.LoadXml("chunk_0.xml")
#success = inputxml.LoadXml(sys.argv[2])
if (success != True):
    print(inputxml.lastErrorText())
    sys.exit()

#print stylexml.getXml()

attributelist = chilkat.CkXml()
attributelist = stylexml.FirstChild()
for i in range(0, attributelist.get_NumChildren()):
    #   access the tag and content directly by index:
    print(str(i) + ": " + attributelist.getChildTagByIndex(i) + " : " + attributelist.getChildContentByIndex(i))

#print("NumChildren = " + str(attributelist.get_NumChildren()))
#attributelist = attributelist.FirstChild()
#print("NumChildren = " + str(attributelist.get_NumChildren()))
#attributelist = attributelist.FirstChild()
#print("NumChildren = " + str(attributelist.get_NumChildren()))
#print attributelist.content()

#searchStyleXml = chilkat.CkXml()
#print searchStyleXml.SearchForAttribute(attributelist,"met:attribute-property","name","name")
#print attributelist.getXml()
#sys.stdout.write(xml.getXml())
#with open(sys.argv[3], 'wb') as csvfile:
#with open("chunk_0.xls", 'wb') as csvfile:
#    outputxml = csv.writer(csvfile, delimiter=' ', quotechar='|', quoting=csv.QUOTE_MINIMAL)
#    attributes = stylexml.FindChild("met:attribute-property")
#    xBeginAfter = attributes.GetSelf()
#    xSearch = attributes.GetSelf()
#    success = xSearch.SearchForAttribute2(xBeginAfter,"met:attribute-property","name","name")
#    while success == True:
#        print(xSearch.content() + ": " + xSearch.getAttrValue("name"))
#        xBeginAfter.CopyRef(xSearch)
#        xSearch.CopyRef(attributes)
#        success = xSearch.SearchForAttribute2(xBeginAfter,"met:attribute-property","name","name")



