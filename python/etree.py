#!/usr/bin/env python
try:
    from lxml import etree
    print("running with lxml.etree")
except ImportError:
    try:
        # Python 2.5
        import xml.etree.cElementTree as etree
        print("running with cElementTree on Python 2.5+")
    except ImportError:
        try:
            # Python 2.5
            import xml.etree.ElementTree as etree
            print("running with ElementTree on Python 2.5+")
        except ImportError:
            try:
            # normal cElementTree install
                import cElementTree as etree
                print("running with cElementTree")
            except ImportError:
                try:
              # normal ElementTree install
                    import elementtree.ElementTree as etree
                    print("running with ElementTree")
                except ImportError:
                    print("Failed to import ElementTree from any known place")

import sys
for i in range(1, len(sys.argv)):
    tree = etree.parse(sys.argv[i])
    root = tree.getroot()
    for doc in root:
        remove = False
        for field in doc:
            if (field.attrib['name'] == 'organization_discussed'):
                if(remove):
                    doc.remove(field)
                else:
                    remove = True
    tree.write(sys.argv[i],encoding='utf-8', xml_declaration=True)
