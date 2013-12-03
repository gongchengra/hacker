def fix_machine(debris, product):
    ### WRITE YOUR CODE HERE ###
    i=0
    while i < len(product):
        j=0
        while j < len(debris):
            if debris[j] == product[i]:
                break
            else:
                j=j+1
        if j==len(debris):
            return "Give me something that's not useless next time."
        else:
            i=i+1
    if i==len(product):
        return product

print "Test case 1: ", fix_machine('UdaciousUdacitee', 'Udacity') == "Give me something that's not useless next time."
print "Test case 2: ", fix_machine('buy me dat Unicorn', 'Udacity') == 'Udacity'
print "Test case 3: ", fix_machine('AEIOU and sometimes y... c', 'Udacity') == 'Udacity'
print "Test case 4: ", fix_machine('wsx0-=mttrhix', 't-shirt') == 't-shirt'
