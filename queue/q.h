#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include"node.h"

class Queue
{
	Node* NewNode();
	Node* NewNode(int inf);
	public:
	Node *front,*rear;
	Queue push(int inf);
	int pop();
	void display();
	int size();
	bool isEmpty();
	Queue()
	{
		front=rear=NULL;
	}
	~Queue(){;}
};

Node* Queue::NewNode()
{
	Node *np=new Node;
	np->next=NULL;
	return np;
}

Node* Queue::NewNode(int inf)
{
	Node *np;
	np=NewNode();
	np->data=inf;
	return np;
}

Queue Queue::push(int inf)
{
	Node* np=NewNode(inf);
	if(front==NULL)
		front=rear=np;
	else
	{
		rear->next=np;
		rear=rear->next;
	}
	return *this;
}

int Queue::pop()
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

void Queue::display()
{
	for(Node *sp=front;sp!=NULL;sp=sp->next)
		cout<<sp->data<<"->";
	cout<<":::\n";
	if(front==NULL)
		if(rear==NULL)
			cout<<"Front is:"<< "NULL"<<"\nRear is:" <<"NULL"<<endl;
		else
			cout<<"Front is:"<< "NULL"<<"\nRear is:" <<rear->data<<endl;
	else
		cout<<"Front is:"<<front->data<<"\nRear is:" <<rear->data<<endl;

}

int Queue::size()
{
	int ret=0;
	for(Node* s=front;s!=NULL;s=s->next)
		ret++;
		
	return ret;
}

bool Queue::isEmpty()
{
	return !front;
}
