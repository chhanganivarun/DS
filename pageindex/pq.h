#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include"node.h"

class PriorityQueue
{
	Node* NewNode();
	Node* NewNode(string inf);
	public:
	Node *front,*rear;
	PriorityQueue push(string inf);
	string pop();
	void display(ostream&);
	void display();
	int size();
	bool isEmpty();
	PriorityQueue()
	{
		front=rear=NULL;
	}
	~PriorityQueue(){;}
};

Node* PriorityQueue::NewNode()
{
	Node *np=new Node;
	np->next=NULL;
	return np;
}

Node* PriorityQueue::NewNode(string inf)
{
	Node *np;
	np=NewNode();
	np->data=inf;
	return np;
}

PriorityQueue PriorityQueue::push(string inf)
{
	Node* np=NewNode(inf);
	if(front==NULL)
		front=rear=np;
	else if(front->data>inf)
	{
		if(front->data==inf)
			return *this;
		np->next=front;
		front=np;
		return *this;
	}
	else
	{
		Node *s;
		for(s=front;s->next!=NULL;s=s->next)
		{
			if(s->next->data>=inf)
				break;
		}
		if(s->next==NULL)
		{
			rear->next=np;
			rear=np;
			return *this;
		}
		else if(s->next->data==inf)
		{
			return *this;
		}
		else
		{
			np->next=s->next;
			s->next=np;
			return *this;
		}
	}	
	return *this;
}

string PriorityQueue::pop()
{
	if(front==NULL)
	{
		cout<<"Underflow!!\n";
		return "";
	}
	if(front->next==NULL)
	{
		rear=NULL;
	}
	Node *np=front;
	front=front->next;
	string ret;
	ret=np->data;
	delete np;
	return ret;
}

void PriorityQueue::display(ostream& fout)
{
	for(Node *sp=front;sp!=NULL;sp=sp->next)
		fout<<sp->data<<"\n";

}
void PriorityQueue::display()
{
	for(Node *sp=front;sp!=NULL;sp=sp->next)
		cout<<sp->data<<"\n";
}

int PriorityQueue::size()
{
	int ret=0;
	for(Node* s=front;s!=NULL;s=s->next)
		ret++;
		
	return ret;
}

bool PriorityQueue::isEmpty()
{
	return !front;
}
