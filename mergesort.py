import random

x = 0
x = int(raw_input())
ar_sorted = []
#ar_sorted = [ int(raw_input()) for m in range(x) ]
    #ar_sorted.append(int(raw_input()))
ar_sorted = [random.randint(1,200) for m in range(x)]
print ar_sorted


def merge(start,mid,last):
    global ar_sorted
    temparr = []
    temparr1 = ar_sorted[start:mid]
    temparr2 = ar_sorted[mid:last]
    startkey1 = 0
    startkey2 = 0
    while startkey1 < len(temparr1) and startkey2 < len(temparr2) :
        if temparr1[startkey1] < temparr2[startkey2] : 
            temparr.append(temparr1[startkey1])
            startkey1 = startkey1 + 1
        else:
            temparr.append(temparr2[startkey2])
            startkey2 = startkey2 + 1

    while startkey1<len(temparr1) :
        temparr.append(temparr1[startkey1])
        startkey1 = startkey1 + 1
    while startkey2<len(temparr2) : 
        temparr.append(temparr2[startkey2])
        startkey2 = startkey2 + 1
    i = start
    for numbers in temparr:
        ar_sorted[i] = numbers
        i = i+1
    return

def mergesort(start,last):
    global ar_sorted
    if start<last-1 :
        mid = (start+last)/2
        mergesort(start,mid)
        mergesort(mid,last)
        merge(start,mid,last)
        return
    else:
        return
mergesort(0,len(ar_sorted))
print ar_sorted

