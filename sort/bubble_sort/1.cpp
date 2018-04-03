#include<bits/stdc++.h>
using namespace std;
#include"ll.h"
int main()
{
	LinkedList l;
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		l.push_back(x);
	}
	int flag=1;
	for(int i=0;flag&&i<n-1;i++)
	{
		flag=0;
		for(Node *s=l.head;s&&s->next;s=s->next)
		{
			if(s->data>s->next->data)
			{
				swap(s->data,s->next->data);
				flag=1;
			}
		}
	}
	l.display();
	cout<<"\n";
	return 0;	
}
