#include<bits/stdc++.h>

using namespace std;

#include"pq.h"

Node *mid(PriorityQueue Q,Node *l,Node *r);
Node* binsearch(PriorityQueue L,int key,Node *l,Node *r)
{
	Node *n=mid(L,l,r);
	if(r->next==l)
		return NULL;
	if(n->priority==key)
		return n;
	if(n->priority>key)
	{
		if((n->next&&n->next->priority<key)||!n->next)
		{
			return NULL;
		}
		return binsearch(L,key,n->next,r);
	}
	return binsearch(L,key,l,n);
}


int main()
{
	int n;
	PriorityQueue Q;
	cout<<"Enter number of integers in the Priority PriorityQueue:";
	cin>>n;
	if(n>0)
		cout<<"Enter "<<n<<" integers with their priorities:";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		int pri;
		cin>>pri;
		Q.push(x,pri);
	}
	cout<<"\nCurrently the Priority PriorityQueue is:"<<endl;
	Q.display();
	
	
	if(Q.front==NULL)
	{
		cout<<"Empty PriorityQueue!!\nAborting!!\n";
		return -1;
	}
	int key;
	cout<<"Enter the priority to search:";
	cin>>key;
	Node *s=binsearch(Q,key,Q.front,Q.rear);
	if(s==NULL)
		cout<<"Not found\n";
	else
	{
		int i=0;
		for(Node *iter=Q.front;iter!=s;iter=iter->next)
			i++;
		cout<<"Found at "<<i<<"\n";
	}
	return 0;
	
}

Node *mid(PriorityQueue Q,Node *l,Node *r)
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

