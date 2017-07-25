if __name__ == '__main__':
#     for y in range(30, -30, -1):
#         for x in range(-30, 30, 1):
#             print('\n'.join([''.join([('Love'[(x-y)%len('Love')])])]))
    print('\n'.join([''.join([('Love'[(x-y)%len('Love')]if((x*0.05)**2+(y*0.1)**2-1)**3-(x*0.05)**2*(y*0.1)**3<=0else' ')for x in range(-30,30)])for y in range(30,-30,-1)]))
