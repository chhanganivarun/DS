#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};

class DoublyLinkedList
{
	Node* NewNode();
	Node* NewNode(int inf);
	Node* NewNode(Node *next_node);
	public:
	Node *head,*tail;
	DoublyLinkedList push_front(int inf);
	DoublyLinkedList push_back(int inf);
	int pop_front();
	int pop_back();
	int pop(Node *key);
	int popindex(int n);
	void display();
	int size();
	Node* NewNode(int inf,Node *next_node);		
	DoublyLinkedList()
	{
		head=tail=NULL;
	}
	~DoublyLinkedList(){;}
};



int main()
{
	int flag=1;
	DoublyLinkedList dll;
	char str[10];
	system("clear");
	while(flag)
	{
		dll.display();
		cout<<"1. Add to front\n"
			<<"2. Add to end\n"
			<<"3. Add before node number\n"
			<<"4. Add after node number\n"
			<<"5. Delete from front\n"
			<<"6. Delete from end\n"
			<<"7. Delete node number\n"
			<<"8. Print LinkList\n"
			<<"9. Exit\n";
		cout<<"Enter Choice:";
		int n,inf;
		cin>>n;
		switch(n)
		{
			case 1:
					cout<<"Enter number to add:";
					cin>>inf;
					dll.push_front(inf);					
					break;
			case 2:
					cout<<"Enter number to add:";
					cin>>inf;
					dll.push_back(inf);					
					break;
			case 3:
					cout<<"Enter Number of node:";
					cin>>inf;
					if(inf==1)
					{
						if(dll.head==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							dll.push_front(inf);					
						}
					}
					else
					{
						int i,n=inf;
						Node *sp=NULL;
						n--;
						for(i=1,sp=dll.head;i<n&&sp!=NULL;i++,sp=sp->next);
						if(i!=n||sp==NULL||sp->next==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							sp->next=dll.NewNode(inf,sp->next);
						}
					}
					break;
			case 4:
					cout<<"Enter Number of node:";
					cin>>inf;
					{
						int i,n=inf;
						Node *sp=NULL;
						for(i=1,sp=dll.head;i<n&&sp!=NULL;i++,sp=sp->next);
						if(i!=n||sp==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							if(sp!=dll.tail)
								sp->next=dll.NewNode(inf,sp->next);
							else
							{
								dll.push_back(inf);
								
							}
						}
					}
					break;
			case 5:
					dll.pop_front();					
					break;
			case 6:
					dll.pop_back();
					break;
			case 7:
					cin>>inf;
					dll.popindex(inf);
					break;
				
			case 8:
					dll.display();
					break;
			case 9:
					flag=0;
					cout<<"Bye\n";
					break;

		}
		if(n<9&&n>0)
		{
			system("read -r -p 'Press enter to continue...' key");
			system("clear");
		}
	}
	return 0;
}


Node* DoublyLinkedList::NewNode()
{
	Node *np=new Node;
	np->next=NULL;
	np->prev=NULL;
	np->data=0;
	return np;
}

Node* DoublyLinkedList::NewNode(int inf)
{
	Node *np;
	np=NewNode();
	np->data=inf;
	return np;
}

Node* DoublyLinkedList::NewNode(Node *next_node)
{
	Node *np=NewNode();
	np->prev=next_node->prev;
	if(np->prev!=NULL)
		np->prev->next=np;
	np->next=next_node;
	if(np->next!=NULL)
		np->next->prev=np;
	return np;
}

Node* DoublyLinkedList::NewNode(int inf,Node *next_node)
{
	Node *np=NewNode(next_node);
	np->data=inf;
	return np;
}
DoublyLinkedList DoublyLinkedList::push_front(int inf)
{
	if(head==NULL)
	{
		tail=head=NewNode(inf);
	}
	else
		head=NewNode(inf,head);
	return *this;
}

DoublyLinkedList DoublyLinkedList::push_back(int inf)
{
	Node* np=NewNode(inf);
	if(head==NULL)
		head=tail=np;
	else
	{
		tail->next=np;
		np->prev=tail;
		tail=tail->next;
	}
	return *this;
}

int DoublyLinkedList::pop_front()
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
	head->prev=NULL;
	int ret=np->data;
	delete np;
	return ret;
}

int DoublyLinkedList::pop_back()
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
	Node *np=tail;
	tail=tail->prev;
	tail->next=NULL;
	int ret=np->data;
	delete np;
	return ret;
}

int DoublyLinkedList::pop(Node *key)
{
	int ret=key->data;
	if(key->prev!=NULL)
		key->prev->next=key->next;
	if(key->next!=NULL)
		key->next->prev=key->prev;
	delete key;
	return ret;
}
int DoublyLinkedList::popindex(int n)
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

void DoublyLinkedList::display()
{
	cout<<"Head->";
	for(Node *sp=head;sp!=NULL;sp=sp->next)
		cout<<sp->data<<"<->";
	cout<<"Tail\n";
	cout<<"Tail->";
	for(Node *sp=tail;sp!=NULL;sp=sp->prev)
		cout<<sp->data<<"<->";
	cout<<"Head\n";
	if(head==NULL)
		if(tail==NULL)
			cout<<"Head is:"<< "NULL"<<"\nTail is:" <<"NULL"<<endl;
		else
			cout<<"Head is:"<< "NULL"<<"\nTail is:" <<tail->data<<endl;
	else
		cout<<"Head is:"<<head->data<<"\nTail is:" <<tail->data<<endl;

}
int DoublyLinkedList::size()
{
	int ret=0;
	for(Node* s=head;s!=NULL;s=s->next)
		ret++;		
	return ret;
}

