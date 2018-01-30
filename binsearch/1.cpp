#include<bits/stdc++.h>

using namespace std;

#include"ll.h"

Node *mid(LinkedList ll,Node *l,Node *r);
Node* binsearch(LinkedList L,int key,Node *l,Node *r)
{
	Node *n=mid(L,l,r);
	if(r->next==l)
		return NULL;
	if(n->data==key)
		return n;
	if(n->data>key)
		return binsearch(L,key,l,n);
	return binsearch(L,key,n->next,r);
}


int main()
{
	int n;
	LinkedList ll;
	cout<<"Enter number of integers in the linked list:";
	cin>>n;
	if(n>0)
		cout<<"Enter "<<n<<" integers:";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ll.push_back(x);
	}
	cout<<"\nCurrently the Linked List is:"<<endl;
	ll.display();
	
	
	if(ll.head==NULL)
	{
		cout<<"Empty List!!\nAborting!!\n";
		return -1;
	}
	int key;
	cout<<"Enter the number to search:";
	cin>>key;
	Node *s=binsearch(ll,key,ll.head,ll.tail);
	if(s==NULL)
		cout<<"Not found\n";
	else
	{
		int i=0;
		for(Node *iter=ll.head;iter!=s;iter=iter->next)
			i++;
		cout<<"Found at "<<i<<"\n";
	}
	return 0;
	
}

Node *mid(LinkedList ll,Node *l,Node *r)
{
	Node *curr=l;
	int curr_cond=0;
	for(Node *sp=l->next;sp!=r->next;sp=sp->next)
	{
		curr_cond=1-curr_cond;
		if(!curr_cond)
		{
			curr=curr->next;
		}
	}
	return curr;
}

