#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int partition(int* a ,int l, int r)
{
	if(l>=r)
		return -1;

	int pivot=(l+r)/2;
	int pivval=(a[l]+a[r-1]+a[pivot])/3;
	pivot=l;
	for(int i=l;i<r;i++)
	{
		if(abs(a[i]-pivval)<abs(a[pivot]-pivval))
		{
			pivot=i;
		}
	}
	
	
	swap(a[pivot],a[r-1]);


	pivot=r-1;
	int left=l-1;

	for(int right=l;right<r-1;right++)
	{
		if(a[right]<=a[pivot])
		{
			left++;
			swap(a[left],a[right]);
		}
	}
	swap(a[left+1],a[pivot]);
	return left+1;
}

void quickSort(int* a ,int l,int r)
{
	int mid;
	if(r<=l)
		return ;
	mid=partition(a,l,r);
	if(mid==-1)return;
	
	quickSort(a,l,mid);
	quickSort(a,mid+1,r);
	
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	quickSort(a,0,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
