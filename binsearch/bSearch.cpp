#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int bSearch(int *a,int l,int r,int key)
{
	if(r<l)
		return -1;
	if(a[(l+r)/2]==key)
		return (l+r)/2;
	if(a[(l+r)/2]>key)
		return bSearch(a,l,(l+r)/2-1,key);
	return bSearch(a,(l+r)/2+1,r,key);
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
	if(x==-1)
		cout<<"Not found\n";
	else
		cout<<"Found at "<<x<<"\n";
	return 0;
	
}

