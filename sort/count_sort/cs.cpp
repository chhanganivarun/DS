#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define size 10
//2 2 4 6 6 7 1 2 5
int main()
{
	int cnt[size];
	int n;
	cout<<"Enter value of n:\n";
	cin>>n;
	int a[n];
	cout<<"Enter "<<n<<" numbers(0-"<<size-1<<"):\n";
	for(int i=0;i<size;i++)
		cnt[i]=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<size;i++)
	{
		cnt[i]+=cnt[i-1];
	}
	int sorted[n];
	for(int i=0;i<n;i++)
		sorted[n]=-1;
	for(int i=n-1;i>=0;i--)
	{
		sorted[cnt[a[i]]-1]=a[i];
		cnt[a[i]]--;
	}
	for(int i=0;i<n;i++)
	{
		cout<<sorted[i]<<" ";
	}
	cout<<endl;
	return 0;
	
	

}
