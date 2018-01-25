#include<bits/stdc++.h>

struct Node
{
	int data;
	Node* next;
};

class Stack
{
	
	Node* NewNode();
	Node* NewNode(int inf);
	public:
	Node *top;
	Node* push(Node *n);
	Node* push(int inf);
	int pop();
	void print(Node* );
	void print();
	int size();
	bool isEmpty();
	Stack() {top=NULL;}
	~Stack(){;}
};

Node* Stack::NewNode()
{
	Node*np= new Node;
	np->next=NULL;
	return np;
}
Node* Stack::NewNode(int inf)
{
	Node* np=NewNode();
	np->data=inf;
}
Node* Stack::push(Node *n)
{
	n->next=top;
	top=n;
	return top;
}
Node* Stack::push(int inf)
{
	return push(NewNode(inf));
}
int Stack::pop()
{
	if(top==NULL)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	Node *np=top;
	int ret=np->data;
	top=top->next;
	delete np;
	return ret;
}
void Stack::print(Node* curr)
{
	for(Node* s=curr;s;s=s->next)
	{
		cout<<s->data<<"\n";
	}
	cout<<":::\n";
}
void Stack::print()
{
	for(Node* s=top;s;s=s->next)
	{
		cout<<s->data<<"\n";
	}
	cout<<":::\n";
}
int Stack::size()
{
	int ret=0;
	for(Node* s=top;s;s=s->next)
		ret++;
	return ret;
}
bool Stack::isEmpty()
{
	if(!top)
		return true;
	return false;
}

