#include<bits/stdc++.h>
using namespace std;
#include"ll.h"
int main()
{
	int n,*a;
	cin>>n;
	LinkedList L;
	a=new int [n];
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		L.push_back(x);
	}
//	cout<<"Input taken\n";
	
	Node *s=L.head->next;
	for(int i=1;i<n&&s;i++,s=s->next)
	{
		int x=s->data;
		if(L.head->data>=x)
		{
			L.push_front(x);
//			cout<<"Pushed at front";
		}
		else
		for(Node *t=L.head;t&&t->next;t=t->next)
		{
			if(t->next->data>=x)
			{
				Node *n=new Node;
				n->next=t->next;
				n->data=x;
				t->next=n;
				break;
			}
		}
		L.pop(s);
	}
	L.display();
	return 0;

}
