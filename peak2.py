import numpy
import random

x = 5
y = 6
#x = int(raw_input())
#y = int(raw_input())

#matrix = [[0 for m in xrange(x) ] for n in xrange(y)]
matrix = [[random.randint(1,10) for m in xrange(x) ] for n in xrange(y)]
print matrix
def globalpeak(a,length):
    print a
    print "\n"
    highest = 0
    for m in xrange(length):
        if a[m]>a[highest]:
            highest = m


    return highest


def peakfinder(startpos,endpos):
    mid = (startpos+endpos)/2
    highest = globalpeak(matrix[mid],x)
    if mid == 0:
        if matrix[mid][highest] > matrix[mid+1][highest]:
            return (mid , highest)
        else :
            return peakfinder(mid+1,endpos)
    elif mid == y-1:
        if matrix[mid][highest]  > matrix[mid-1][highest]:
            return (mid,highest)
        else:
            return peakfinder(startpos,mid-1)
    else :
        if matrix[mid][highest] > matrix[mid-1][highest] and matrix[mid][highest] > matrix[mid+1][highest]:
            return (mid , highest)
        elif matrix[mid][highest] < matrix[mid-1][highest]:
            return peakfinder(startpos,mid-1)
        else :
            return peakfinder(mid+1,endpos)
    
if __name__ == "__main__" : 
    answer = peakfinder(0,y-1)
    print answer
