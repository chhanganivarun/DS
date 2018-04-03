#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int bSearch(int *a,int l,int r,int key)
{
	if(r<l)
	{
/*
		if(r!=-1)
			return r;
*/
		return r;
	}
	int mid=(l+r)/2;
	if(a[mid]==key)
		return mid;
	if(a[mid]<key)
	{
/*
		if(a[mid+1]>key)
			return mid;
*/
		return bSearch(a,mid+1,r,key);
	}
	return bSearch(a,l,mid-1,key);
}


int main()
{
	int n;
	cout<<"Enter number of integers in the array:";
	cin>>n;
	int a[n];
	if(n>0)
		cout<<"Enter "<<n<<" integers:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nCurrently the array is:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	int key;
	cout<<"Enter the number to search:";
	cin>>key;
	int x=bSearch(a,0,n-1,key);
	cout<<"Found "<<a[x]<<" at index="<<x<<"\n";
	return 0;
	
}

