#include<iostream>
#include<bits/stdc++.h>
#include"float_ins_sort.h"
#include<limits.h>
//Only for 0.xxx 
int main()
{
	int n;
	cin>>n;
	float a[n];
	float max=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	LinkedList buckets[11];
	for(int i=0;i<n;i++)
	{
		int x=a[i]*10;
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
