#!/usr/bin/python

import sys
import csv
import xml.etree.ElementTree as ET
#import xml.etree.cElementTree as ET
#import lxml.etree as ET

stylexml = ET.parse("ahiv_v1.xml")
inputxml = ET.parse("chunk_0.xml")
#root = stylexml.getroot()
#attributelist = root[0][0][0]
#print attributelist.tag, attributelist.attrib, attributelist.text
#attributelist = root[0]
#for child in attributelist:
#    print child.tag, child.attrib
#NS = 'http://alexanderstreetpress.com/ns/ontology/'
#name = root.findall(".//{%s}met:attribute-property[@name = 'name']" % NS)
#name = root.findall(".//{http://alexanderstreetpress.com/ns/ontology/}met:attribute-property[@name = 'name']")
NS = {'met':'http://alexanderstreetpress.com/ns/ontology/'}
#name = root.findall(".//met:attribute-property[@name = 'name']",namespaces = NS)
#name = root.findall(".//met:attribute-definition",namespaces = NS)
name = stylexml.iterfind('.//met:attribute-property[@name="name"]',namespaces = NS)
#for elem in stylexml.iterfind('.//met:attribute-property[@name="name"]',namespaces = NS):
#    print elem.tag, elem.attrib, elem.text
idx = 0
fieldlist = {}
for elem in name:
    fieldlist[idx] = elem.text
    idx = idx +1

root = inputxml.getroot()
#print root[0][0]
for docs in root:
    for field in docs:
        if(field.attrib['name'] == 'asp_community'):
            print field.attrib, field.text

