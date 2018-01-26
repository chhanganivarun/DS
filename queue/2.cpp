#include<bits/stdc++.h>
using namespace std;
#include"q.h"
#include"../stack/stck.h"
int main()
{
	Stack S;
	Queue q;
	int n;
	cout<<"Enter number of integers (The Number entered must be even):";
	cin>>n;
	if(n&1)
	{
		cout<<"Input integer is odd!!\nAborting\n";
		return -1;
	}
	cout<<"Enter "<<n<<" integers:";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		q.push(x);
	}
	q.display();
	if(q.isEmpty())
	{
		cout<<"Empty Queue!!\nAborting!!\n";
		return -1;
	}
	n=q.size();
	if(n&1)
	{
		cout<<"Input integer is odd!!\nAborting\n";
		return -1;
	}
	for(int i=0;i<(n/2);i++)
	{
		S.push(q.pop());
	}
	while(!S.isEmpty())
	{
		q.push(S.pop());
	}
	for(int i=0;i<(n/2);i++)
	{
		S.push(q.pop());
	}
	for(int i=0;i<n;i++)
	{
		if(i&1)
			q.push(q.pop());
		else
			q.push(S.pop());	
	}
	for(int i=0;i<n;i++)
	{
		S.push(q.pop());
	}
	while(!S.isEmpty())
	{
		q.push(S.pop());
	}
	q.display();
	return 0;
}
