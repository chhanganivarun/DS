#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
struct Node{
	int data;
	Node* next;
};

class LinkedList
{
	Node* NewNode();
	Node* NewNode(int inf);
	Node* NewNode(Node *next_node);
	public:
	Node *head,*tail;
	LinkedList push_front(int inf);
	LinkedList push_back(int inf);
	int pop_front();
	int pop_back();
	int pop(Node *key);
	int popindex(int n);
	void display();
	int size();
	int min();
	Node* NewNode(int inf,Node *next_node);		
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

Node* LinkedList::NewNode(int inf)
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

Node* LinkedList::NewNode(int inf,Node *next_node)
{
	Node *np=NewNode(inf);
	np->next=next_node;
	return np;
}
LinkedList LinkedList::push_front(int inf)
{
	if(head==NULL)
		tail=head=NewNode(inf,head);
	else
		head=NewNode(inf,head);
	return *this;
}

LinkedList LinkedList::push_back(int inf)
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

int LinkedList::pop_front()
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
	int ret=np->data;
	delete np;
	return ret;
}

int LinkedList::pop_back()
{
	if(head==NULL)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	if(head->next==NULL)
	{
		Node *np=tail;
		int ret=np->data;
		head=tail=NULL;
		delete np;
		return ret;
	}
	Node *sp;
	for(sp=head;sp->next->next!=NULL;sp=sp->next);
	tail=sp;
	int ret=sp->next->data;
	delete sp->next;
	tail->next=NULL;
	return ret;
}

int LinkedList::pop(Node *key)
{
	int ret=key->data;
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
int LinkedList::popindex(int n)
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
int LinkedList::min()
{
	if(!head)
	{
		cout<<"Empty List!!";
		return -1;
	}
	int ret=head->data;
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
