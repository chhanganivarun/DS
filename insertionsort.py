import random

x = 0
x = int(raw_input())
ar_sorted = []
#ar_sorted = [ int(raw_input()) for m in range(x) ]
    #ar_sorted.append(int(raw_input()))
ar_sorted = [random.randint(1,200) for m in range(x)]
print ar_sorted

def inserter(pos):
    global ar_sorted
    while ar_sorted[pos-1]>ar_sorted[pos] and pos != 0:
        ar_sorted[pos-1] = ar_sorted[pos-1] + ar_sorted[pos]
        ar_sorted[pos] = ar_sorted[pos-1] - ar_sorted[pos]
        ar_sorted[pos-1] = ar_sorted[pos-1] - ar_sorted[pos]
        pos = pos - 1

def insertionsort():
    global ar_sorted
    for pos in range(1,len(ar_sorted)):
        inserter(pos)



if __name__ == "__main__":
    insertionsort()
    print ar_sorted