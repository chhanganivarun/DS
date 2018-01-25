#include<bits/stdc++.h>
using namespace std;

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

int main()
{
	system("clear");
	int opt,flag=1;
	Stack s;
	while(flag)
	{
		cout<<"1. Push new Element on the stack\n"
			<<"2. Pop Element from top of stack\n"
			<<"3. Print elements in the stack\n"
			<<"4. Exit\n"
			<<"Enter Choice:";
		cin>>opt;
		switch(opt)
		{
			case 1:
					int inf;
					cout<<"Enter data to insert on the stack:";
					cin>>inf;
					s.push(inf);
					break;
			case 2:
					if(s.size())
						cout<<s.pop()<<" has been popped\n";
					else
						s.pop();
					break;
			case 3:
					s.print();
					break;
			case 4:
					cout<<"Bye\n";
					flag=0;
					break;
					
		}
		system("read -r -p 'Press enter to continue...' key");
		system("clear");
		
	}
	return 0;	
}

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

