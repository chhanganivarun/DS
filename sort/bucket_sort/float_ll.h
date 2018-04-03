#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include"float_node.h"
class LinkedList
{
	Node* NewNode();
	Node* NewNode(float inf);
	Node* NewNode(Node *next_node);
	public:
	Node *head,*tail;
	LinkedList push_front(float inf);
	LinkedList push_back(float inf);
	float pop_front();
	float pop_back();
	float pop(Node *key);
	float popindex(int n);
	void display();
	int size();
	float min();
	Node* NewNode(float inf,Node *next_node);		
	LinkedList()
	{
		head=tail=NULL;
	}
	~LinkedList(){;}
};

Node* LinkedList::NewNode()
{
	Node *np=new Node;
	np->next=NULL;
	return np;
}

Node* LinkedList::NewNode(float inf)
{
	Node *np;
	np=NewNode();
	np->data=inf;
	return np;
}

Node* LinkedList::NewNode(Node *next_node)
{
	Node *np=NewNode();
	np->next=next_node;
	return np;
}

Node* LinkedList::NewNode(float inf,Node *next_node)
{
	Node *np=NewNode(inf);
	np->next=next_node;
	return np;
}
LinkedList LinkedList::push_front(float inf)
{
	if(head==NULL)
		tail=head=NewNode(inf,head);
	else
		head=NewNode(inf,head);
	return *this;
}

LinkedList LinkedList::push_back(float inf)
{
	Node* np=NewNode(inf);
	if(head==NULL)
		head=tail=np;
	else
	{
		tail->next=np;
		tail=tail->next;
	}
	return *this;
}

float LinkedList::pop_front()
{
	if(head==NULL)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	if(head->next==NULL)
	{
		tail=NULL;
	}
	Node *np=head;
	head=head->next;
	float ret=np->data;
	delete np;
	return ret;
}

float LinkedList::pop_back()
{
	if(head==NULL)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	if(head->next==NULL)
	{
		Node *np=tail;
		float ret=np->data;
		head=tail=NULL;
		delete np;
		return ret;
	}
	Node *sp;
	for(sp=head;sp->next->next!=NULL;sp=sp->next);
	tail=sp;
	float ret=sp->next->data;
	delete sp->next;
	tail->next=NULL;
	return ret;
}

float LinkedList::pop(Node *key)
{
	float ret=key->data;
	if(head==key)
	{
		this->pop_front();
		return ret;
	}
	Node *sp;
	for(sp=head;sp->next!=key;sp=sp->next);
	Node *n=sp->next;
	
	
	if(n==tail)
	{
		tail=sp;
	}
	sp->next=sp->next->next;
	delete n;
	return ret;
}
float LinkedList::popindex(int n)
{
	int i;
	Node *sp=NULL;
	for(i=1,sp=head;i<n&&sp!=NULL;i++,sp=sp->next);
	if(i!=n||sp==NULL)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	else
	{
		return pop(sp);					
	}
}

void LinkedList::display()
{
	for(Node *sp=head;sp!=NULL;sp=sp->next)
		cout<<sp->data<<"->";
	cout<<":::\n";
	if(head==NULL)
		if(tail==NULL)
			cout<<"Head is:"<< "NULL"<<"\nTail is:" <<"NULL"<<endl;
		else
			cout<<"Head is:"<< "NULL"<<"\nTail is:" <<tail->data<<endl;
	else
		cout<<"Head is:"<<head->data<<"\nTail is:" <<tail->data<<endl;

}
float LinkedList::min()
{
	if(!head)
	{
		cout<<"Empty List!!";
		return -1;
	}
	float ret=head->data;
	for(Node *s=head;s;s=s->next)
		ret=(ret>s->data?s->data:ret);
	return ret;
}
int LinkedList::size()
{
	int ret=0;
	for(Node* s=head;s!=NULL;s=s->next)
		ret++;
		
	return ret;
}
