import random
x = 0
x = int(raw_input())
ar_sorted = []
ar_sorted = [ random.randint(1,200) for m in range(x)]
print ar_sorted

def heapify(x):
    global ar_sorted
    length_ar = len(ar_sorted)
    left = 2*x + 1
    right = left + 1
    greatest = x
    if left < length_ar and ar_sorted[greatest] < ar_sorted[left]: 
        greatest = left 

    if right < length_ar and ar_sorted[greatest] < ar_sorted[right]: 
        greatest = right

    if greatest != x :
        temp = ar_sorted[greatest]
        ar_sorted[greatest] = ar_sorted[x]
        ar_sorted[x] = temp
        heapify(greatest)
    else :
         return

def make_heap():
    global ar_sorted
    half_length_ar = len(ar_sorted)/2
    print half_length_ar
    for i in range(0,half_length_ar+1):
        x =  half_length_ar - i 
        print x
        heapify(x)

def sort_array():
    temp_array = []
    global ar_sorted
    while (len(ar_sorted) != 0):
        temp_array.append(ar_sorted[0])
        ar_sorted[0] = ar_sorted[len(ar_sorted)-1]
        ar_sorted.pop(len(ar_sorted) - 1)
        heapify(0)

    return temp_array

if __name__ == "__main__" : 
    make_heap()
    sorted_array = sort_array()
    print sorted_array