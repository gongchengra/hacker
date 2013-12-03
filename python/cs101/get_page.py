def get_page(url):
    try:
        import urllib
        return urllib.urlopen(url).read()
    except:
        return ""

def get_next_target(page):
    start_link = page.find('<a href=')
    if start_link == -1:
        return None,0
    else:
        start_quote = page.find('"', start_link)
        end_quote = page.find('"', start_quote + 1)
        url = page[start_quote + 1:end_quote]
        return url, end_quote

def print_all_links(page):
    while True:
        url,endpos = get_next_target(page)
        if url:
            print url
            page = page[endpos:]
        else:
            break

def union(p,q):
    for e in q:
        if e not in p:
            p.append(e)
            
def get_all_links(page):
    links = []
    while True:
        url,endpos = get_next_target(page)
        if url:
            links.append(url)
            page = page[endpos:]
        else:
            break
    return links

def add_to_index(index,keyword,url):
    for ei in index:
        if keyword == ei[0]:
            if not url in ei[1]:
                ei[1].append(url)
            return index
    index.append([keyword,[url]])
    return index

def split_string(source,splitlist):
    i = 0
    flag = True
    result = []
    while(i<len(source)):
        if source[i] in splitlist:
            flag = True
        else:
            if flag:
                result.append(source[i])
                flag = False
            else:
                result[-1]=result[-1]+source[i]
        i = i + 1
    return result

def split_string_ans(source,splitlist):
    output = []
    atsplit = True
    for char in source:
        if char in splitlist:
            atsplit = True
        else:
            if atsplit:
                output.append(char)
                atsplit = False
            else:
                output[-1]=output[-1]+char
    return output             
    
#out = split_string("This is a test-of the,string separation-code!"," ,!-")
#print out
#out = split_string("After  the flood   ...  all the colors came out.", " .")
#print out
#out = split_string("Hi! I am your Assistant Instructor, Peter.", "! ,.")
#print out
#out = split_string("First Name,Last Name,Street Address,City,State,Zip Code",",")
#print out

def add_page_to_index(index,url,content):
    for word in content.split():
        add_to_index(index, word, url)

def crawl_web(seed):
    tocrawl = seed
    crawled = []
    index = []
    while tocrawl:
        page = tocrawl.pop()
        if page not in crawled:
            content = get_page(page)
            add_page_to_index(index,page,content)
            union(tocrawl, get_all_links(content))
            crawled.append(page)
    return index

def crawl_web_maxpage(seed, maxpages):
    tocrawl = seed
    crawled = []
    while tocrawl:
        page = tocrawl.pop()
        if page not in crawled  and len(crawled)<=maxpages:
            union(tocrawl, get_all_links(get_page(page)))
            crawled.append(page)
    return crawled

def crawl_web_depth(seed, maxdepth):
    tocrawl = seed
    crawled = []
    next_depth = []
    depth = 0
    while tocrawl and depth <= maxdepth:
        page = tocrawl.pop()
        print page
        if page not in crawled:
            union(next_depth, get_all_links(get_page(page)))
            crawled.append(page)
        if not tocrawl:
            tocrawl, next_depth = next_depth, tocrawl
            depth = depth + 1
    return crawled

def lookup(index,keyword):
    for ei in index:
        if keyword == ei[0]:
            return ei[1]
    return []

#page=get_page('http://www.udacity.com/cs101x/index.html')
#seed = get_all_links(page)
seed = ['http://www.udacity.com/cs101x/index.html']
print lookup(crawl_web(seed),'<html>')

#page=get_page('http://news.qq.com')   
#page=get_page('http://www.udacity.com/cs101x/index.html')
#print_all_links(page)
#print get_all_links(page)
#seed = get_all_links(page)
#seed=['http://news.qq.com']
#seed = ['http://www.udacity.com/cs101x/index.html']
#print len(seed)
#print len(crawl_web_maxpage(seed, 100))
#print crawl_web_maxpage(seed, 100)
#print crawl_web_depth(seed, 1)
#print len(seed) == len(crawl_web_depth(seed, 1))
#print crawl_web_maxpage(seed, 100):
