#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include"node.h"

class PriorityQueue
{
	Node* NewNode();
	Node* NewNode(int inf,int);
	public:
	Node *front,*rear;
	PriorityQueue push(int inf,int);
	int pop();
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

Node* PriorityQueue::NewNode(int inf,int pri)
{
	Node *np;
	np=NewNode();
	np->data=inf;
	np->priority=pri;
	return np;
}

PriorityQueue PriorityQueue::push(int inf,int pri)
{
	Node* np=NewNode(inf,pri);
	if(front==NULL)
		front=rear=np;
	else if(front->priority<pri)
	{
		np->next=front;
		front=np;
		return *this;
	}
	else
	{
		Node *s;
		for(s=front;s->next!=NULL;s=s->next)
		{
			if(s->next->priority<pri)
				break;
		}
		if(s->next==NULL)
		{
			rear->next=np;
			rear=np;
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

int PriorityQueue::pop()
{
	if(front==NULL)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	if(front->next==NULL)
	{
		rear=NULL;
	}
	Node *np=front;
	front=front->next;
	int ret=np->data;
	delete np;
	return ret;
}

void PriorityQueue::display()
{
	for(Node *sp=front;sp!=NULL;sp=sp->next)
		cout<<sp->data<<"->";
	cout<<":::\n";
	for(Node *sp=front;sp!=NULL;sp=sp->next)
		cout<<sp->priority<<"->";
	cout<<":::\n";
	if(front==NULL)
		if(rear==NULL)
			cout<<"Front is:"<< "NULL"<<"\nRear is:" <<"NULL"<<endl;
		else
			cout<<"Front is:"<< "NULL"<<"\nRear is:" <<rear->data<<endl;
	else
		cout<<"Front is:"<<front->data<<"\nRear is:" <<rear->data<<endl;

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
