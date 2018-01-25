#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
struct Node{
	char data;
	Node* next;
};

class LinkedList
{
	Node* NewNode();
	Node* NewNode(char inf);
	Node* NewNode(Node *next_node);
	public:
	Node *head,*tail;
	LinkedList push_front(char inf);
	LinkedList push_back(char inf);
	char pop_front();
	char pop_back();
	char pop(Node *key);
	Node* return_index(int n);
	char popindex(int n);
	void display();
	int size();
	char min();
	Node* NewNode(char inf,Node *next_node);		
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

Node* LinkedList::NewNode(char inf)
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

Node* LinkedList::NewNode(char inf,Node *next_node)
{
	Node *np=NewNode(inf);
	np->next=next_node;
	return np;
}
LinkedList LinkedList::push_front(char inf)
{
	if(head==NULL)
		tail=head=NewNode(inf,head);
	else
		head=NewNode(inf,head);
	return *this;
}

LinkedList LinkedList::push_back(char inf)
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

char LinkedList::pop_front()
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
	char ret=np->data;
	delete np;
	return ret;
}

char LinkedList::pop_back()
{
	if(head==NULL)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	if(head->next==NULL)
	{
		Node *np=tail;
		char ret=np->data;
		head=tail=NULL;
		delete np;
		return ret;
	}
	Node *sp;
	for(sp=head;sp->next->next!=NULL;sp=sp->next);
	tail=sp;
	char ret=sp->next->data;
	delete sp->next;
	tail->next=NULL;
	return ret;
}

char LinkedList::pop(Node *key)
{
	char ret=key->data;
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
char LinkedList::popindex(int n)
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

Node* LinkedList::return_index(int n)
{
	int i;
	Node *sp=NULL;
	for(i=1,sp=head;i<n&&sp!=NULL;i++,sp=sp->next);
	if(i!=n||sp==NULL)
	{
		cout<<"Underflow!!\n";
		return NULL;
	}
	else
	{
		return sp;					
	}
}

void LinkedList::display()
{
	for(Node *sp=head;sp!=NULL;sp=sp->next)
		cout<<sp->data;
	cout<<"\n";

}
char LinkedList::min()
{
	if(!head)
	{
		cout<<"Empty List!!";
		return -1;
	}
	char ret=head->data;
	for(Node *s=head;s;s=s->next)
		ret=(ret>s->data?s->data:ret);
	return ret;
}
int LinkedList::size()
{
	char ret=0;
	for(Node* s=head;s!=NULL;s=s->next)
		ret++;
		
	return ret;
}
