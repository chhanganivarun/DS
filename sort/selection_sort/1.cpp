#include<bits/stdc++.h>
using namespace std;
#include"ll.h"
int main()
{
	int n;
	cin>>n;
	LinkedList L;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		L.push_back(x);
	}
	int i=0,j;
	for(Node *s=L.head;s->next;s=s->next,i++)
	{
		
		for(Node *t=s->next;t;t=t->next,j++)
		{
			if(t->data<s->data)
			{
				swap(t->data,s->data);
			}
		}
		
	}
	L.display();
	return 0;	
}
