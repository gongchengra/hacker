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
    if keyword in index:
        index[keyword].append(url)
    else:
        index[keyword] = [url]

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
    
def add_page_to_index(index,url,content):
    for word in content.split():
        add_to_index(index, word, url)

def crawl_web(seed):
    tocrawl = seed
    crawled = []
    index = {}
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
    index = {}
    while tocrawl:
        page = tocrawl.pop()
        if page not in crawled  and len(crawled)<=maxpages:
            content = get_page(page)
            add_page_to_index(index,page,content)
            union(tocrawl, get_all_links(content))
            crawled.append(page)
    return index

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
    if keyword in index:
        return index[keyword]
    else:
        return None
    
def hashtable_update(htable,key,value):
    # Your code here
    bucket = hashtable_get_bucket(htable,key)
    for entry in bucket:
        if entry[0] == key:
            entry[1] = value
            return htable
    bucket.append([key,value])
    return htable
            
def hashtable_lookup(htable,key):
    for e in hashtable_get_bucket(htable,key):
        if e[0] == key:
            return e[1]
    return None
    
def hashtable_add(htable,key,value):
    hashtable_get_bucket(htable,key).append([key,value])
    
def hashtable_get_bucket(htable,keyword):
    return htable[hash_string(keyword, len(htable))]
    
def hash_string(keyword,buckets):
    out = 0
    for s in keyword:
        out = (out + ord(s)) % buckets
    return out

def make_hashtable_while(nbuckets):
    index = []
    i = 0
    while i < nbuckets:
        index.append([])
        i = i + 1
    return index

def make_hashtable(nbuckets):
    index = []
    for e in range(nbuckets):
        index.append([])
    return index

#print make_hashtable(3)
#page=get_page('http://www.udacity.com/cs101x/index.html')
#seed = get_all_links(page)
#seed = ['http://www.udacity.com/cs101x/index.html']
#print lookup(crawl_web(seed),'<html>')
seed=['http://news.qq.com']
print crawl_web_maxpage(seed,10)
#print lookup(crawl_web_maxpage(seed,10),'qq')

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
