#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define size 10
//2 2 4 6 6 7 1 2 5
int *cSort(int *a,int n,int exp)
{
	int cnt[size];
	for(int i=0;i<size;i++)
		cnt[i]=0;
	for(int i=0;i<n;i++)
	{
		cnt[(a[i]/exp)%10]++;
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
		sorted[cnt[(a[i]/exp)%10]-1]=a[i];
		cnt[(a[i]/exp)%10]--;
	}
	for(int i=0;i<n;i++)
	{
		a[i]=sorted[i];
	}
	return a;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	int maxim=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>maxim)
			maxim=a[i];
	}
	for(int exp=1;maxim/exp;exp*=10)
	{
		cSort(a,n,exp);
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
			
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}
