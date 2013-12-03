# By Websten from forums
#
# Given your birthday and the current date, calculate your age in days. 
# Compensate for leap days. 
# Assume that the birthday and current date are correct dates (and no time travel). 
# Simply put, if you were born 1 Jan 2012 and todays date is 2 Jan 2012 
# you are 1 day old.
#
# Hint
# A whole year is 365 days, 366 if a leap year. 
# If you know how many days it is from 1 Jan until a certain date, 
# you also know how many days there are left from that date until 31 Dec.

daysOfMonths = [ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def isLeapYear(year):
    ##
    # Your code here. Return True or False
    # Pseudo code for this algorithm is found at
    # http://en.wikipedia.org/wiki/Leap_year#Algorithm
    ##
    return year%400 == 0 or (year%4 == 0 and year%100 != 0)

def daysFromJan1(year,month,day):
    days = 0
    imonth = 0
    while(imonth<month-1):
        days = days + daysOfMonths[imonth]
        if(imonth==1 and isLeapYear(year)):
            days=days+1
        imonth = imonth + 1
    days = days + day - 1 
    return days

def daysBetweenDates(year1, month1, day1, year2, month2, day2):
    ##
    # Your code here.
    ##
    days = 0
    days1 = daysFromJan1(year1, month1, day1)
    days2 = daysFromJan1(year2, month2, day2)
    while(year1 < year2):
        if isLeapYear(year1):
            daysofyear = 366
        else:
            daysofyear = 365
        days = days + daysofyear
        year1=year1+1
    days = days + days2 - days1
    return days

print daysBetweenDates(1986,1,25,2012,11,8)
'''
# Test routine

def test():
    test_cases = [((2012,1,1,2012,2,28), 58), 
                  ((2012,1,1,2012,3,1), 60),
                  ((2011,6,30,2012,6,30), 366),
                  ((2011,1,1,2012,8,8), 585),
                  ((1900,1,1,1999,12,31), 36523)]
    for (args, answer) in test_cases:
        result = daysBetweenDates(*args)
        if result != answer:
            print "Test with data:", args, "failed"
        else:
            print "Test case passed!"

test()
'''
