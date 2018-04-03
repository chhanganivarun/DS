#include<iostream>
#include<bits/stdc++.h>
#include"ins_sort.h"
#include<limits.h>

int main()
{
	int n;
	cin>>n;
	int a[n];
	int max=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
			max=a[i];
	}
	int pow=1;
	while(max/(pow*10))pow*=10;
	LinkedList buckets[11];
	for(int i=0;i<n;i++)
	{
		int x=abs(a[i]/pow);
		buckets[x].push_back(a[i]);
		cout<<x<<endl;
	}
	int curr=0;
	for(int i=0;i<=10;i++)
	{
		buckets[i]=ins_sort(buckets[i]);
		for(Node *s=buckets[i].head;s;s=s->next)
			a[curr++]=s->data;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
