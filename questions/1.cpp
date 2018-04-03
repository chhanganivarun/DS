/**************************************************
One Independence day, a jailer wants to leave one 
prisoner and kill rest all. For this he makes them
stand in a circle and gives a knife to prisoner
number 1. He asks prisoner 1 to stab next prisoner
and pass the knife to next prisoner alive.
Given N number of prisoners, find which prisoner 
will get to escape?
**************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	vector<pair<long long, bool> > a;
	for(long long i=0;i<n;i++)
	{
		a.push_back(make_pair(i+1,1));
	}
	bool flag=1;
	long long fina=a[0].first;
	while(flag)
	{
		vector<pair<long long, bool> > b;
		long long cnt=0;
		flag=0;
		for(long long i=0;i<n;i++)
		{
			if(a[i].second)
			{
				b.push_back(make_pair(a[i].first,1));
				cnt++;
				cout<<a[i].first<<" ";
			}
		}
		cout<<endl;
		if(cnt)
		{
			flag=1;
			fina=b[0].first;
		}	
		long long len=b.size();
		for(long long i=0;i<len;i+=2)
		{
			a[b[(i+1)%len].first-1].second=0;
		}
	}
	cout<<fina<<endl;
	return 0;
	
}
