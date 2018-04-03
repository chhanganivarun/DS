#include<bits/stdc++.h>
using namespace std;
#include"float_ll.h"
LinkedList ins_sort(LinkedList &L)
{
	if(L.head==NULL)
		return L;
	Node *s=L.head->next;
	int n=L.size();
	for(int i=1;i<n&&s;i++,s=s->next)
	{
		float x=s->data;
		if(L.head->data>=x)
		{
			L.push_front(x);
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
	return L;
}
