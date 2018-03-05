#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int tSearch(int *a,int l,int r,int key)
{
	if(r<l)
		return -1;
	int mid1,mid2;
	mid1=l+(r-l)/3;
	mid2=l+2*(r-l)/3;
	if(a[mid1]==key)
		return mid1;
	if(a[mid1]>key)
		return tSearch(a,l,mid1-1,key);
	if(a[mid2]>key)
		return tSearch(a,mid1+1,mid2-1,key);
	if(a[mid2]==key)
		return mid2;
	return tSearch(a,mid2+1,r,key);
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
	int x=tSearch(a,0,n-1,key);
	if(x==-1)
		cout<<"Not found\n";
	else
		cout<<"Found at "<<x<<"\n";
	return 0;
	
}

