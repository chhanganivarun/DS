save = []

def greedyfunction(save,start,end,arraylength):
	mid = (start+end)/2
	if mid == 0:
		if save[mid]>save[mid+1] :
			return save[mid]
		else:
			return 9991
	elif mid == arraylength :
		if save[mid]>save[arraylength-1] :
			return save[mid]
		else:
			return 9992
	else:
		if save[mid]>save[mid-1] and save[mid]>save[mid+1] :
			return save[mid]
		elif save[mid]<save[mid-1] :
			return greedyfunction(save,start,mid,arraylength)
		else :
			return greedyfunction(save,mid+1,end,arraylength)




number = int(raw_input())
for i in range (number):
	inputint = int(raw_input())
	save.insert(i,inputint)
lenofarray = len(save)
answer = greedyfunction(save,0,lenofarray-1,lenofarray-1)
print answer