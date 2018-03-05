#include<iostream>
#include<bits/std/c++.h>
using namespace std;
int partition(vector<int> a ,int l, int r)
{
	
}

int quickSort(vector<int>a ,int l,int r)
{
	int mid;
	mid=partition(a,l,r);
	quickSort(a,l,mid);
	quickSort(a,mid,r);
	
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	quickSort(a,0,n);
}
