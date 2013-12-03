# [Double Gold Star] Memoization is a way to make code run faster by saving
# previously computed results.  Instead of needing to recompute the value of an
# expression, a memoized computation first looks for the value in a cache of
# pre-computed values.

# Define a procedure, cached_execution(cache, proc, proc_input), that takes in
# three inputs: a cache, which is a Dictionary that maps inputs to proc to
# their previously computed values, a procedure, proc, which can be called by
# just writing proc(proc_input), and proc_input which is the input to proc.
# Your procedure should return the value of the proc with input proc_input,
# but should only evaluate it if it has not been previously called.

import time

def time_execution_single(function, inputs):
    start = time.clock()
    result = function(inputs)
    runtime = time.clock()-start
    return result, runtime

def time_execution(function, inputs):
    start = time.clock()
    result = function(*inputs)
    runtime = time.clock()-start
    return result, runtime

def cached_execution(cache, proc, proc_input):
    if proc_input not in cache:
        cache[proc_input]=proc(proc_input)
    return cache[proc_input]
        
        
    # Your code here


# Here is an example showing the desired behavior of cached_execution:

def factorial(n):
    print "Running factorial"
    result = 1
    for i in range(2, n + 1):
        result = result * i
    return result

cache = {} # start cache as an empty dictionary
### first execution (should print out Running factorial and the result)
print time_execution(cached_execution, (cache, factorial, 50))
print "Second time:"
### second execution (should only print out the result)
print time_execution(cached_execution, (cache, factorial, 50))

# Here is a more interesting example using cached_execution
# (do not worry if you do not understand this, though,
# it will be clearer after Unit 6):

def fibo(n):
    if n == 1 or n == 0:
        return n
    else:
        return fibo(n - 1 ) + fibo(n - 2 )

def fibonacci(n):
    f0 = 0
    f1 = 1
    i=0
    while i < n:
        f0, f1 = f1, f0 + f1
    return f0

def fibonacci_ans(n):
    current = 0
    after = 1
    for i in range(n):
        current, after =after, current+after
    return current

def cached_fibo(n):
    if n == 1 or n == 0:
        return n
    else:
        return (cached_execution(cache, cached_fibo, n - 1 )
               + cached_execution(cache,  cached_fibo, n - 2 ))
               
cache = {} # new cache for this procedure
# do not try this at home...at least without a cache!
print time_execution(cached_execution, (cache, cached_fibo, 100))
print time_execution(cached_execution, (cache, fibo, 100))
print time_execution_single(fibonacci_ans, 200)
print time_execution_single(fibonacci, 100)

mass_of_earth = 5.9722* 10**24
mass_of_rabbit = 2
n = 1
while fibonacci(n) * mass_of_rabbit < mass_of_earth:
    n = n + 1
print n, fibonacci(n)

