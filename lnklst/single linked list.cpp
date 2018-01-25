#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};
Node* NewNode();
Node* NewNode(int inf);
Node *NewNode(Node *next_node);
Node *NewNode(int inf,Node *next_node);

Node* NewNode()
{
	Node *np=new Node;
	np->next=NULL;
	return np;
}

Node* NewNode(int inf)
{
	Node *np;
	np=NewNode();
	np->data=inf;
	return np;
}

Node *NewNode(Node *next_node)
{
	Node *np=NewNode();
	np->next=next_node;
	return np;
}

Node *NewNode(int inf,Node *next_node)
{
	Node *np=NewNode(inf);
	np->next=next_node;
	return np;
}

pair<Node*,Node*> push_front(int inf,Node *head,Node *tail)
{
	if(head==NULL)
		tail=head=NewNode(inf,head);
	else
		head=NewNode(inf,head);
	return make_pair(head,tail);
}

pair<Node*,Node*> push_back(int inf,Node *head,Node *tail)
{
	Node* np=NewNode(inf);
	if(head==NULL)
		head=tail=np;
	else
	{
		tail->next=np;
		tail=tail->next;
	}
	return make_pair(head,tail);
}

pair<Node*,Node*> pop_front(Node *head,Node *tail)
{
	if(head==NULL)
	{
		cout<<"Underflow!!\n";
		return make_pair(head,tail);
	}
	if(head->next==NULL)
	{
		tail=NULL;
	}
	Node *np=head;
	head=head->next;

	delete np;
	return make_pair(head,tail);
}

pair<Node*,Node*> pop_back(Node *head,Node* tail)
{
	if(head==NULL)
	{
		cout<<"Underflow!!\n";
		return make_pair(head,tail);
	}
	if(head==NULL)
		return make_pair(head,tail);
	if(head->next==NULL)
	{
		head=tail=NULL;
		return make_pair(head,tail);
	}
	Node *sp;
	for(sp=head;sp->next->next!=NULL;sp=sp->next);
	tail=sp;
	delete sp->next;
	tail->next=NULL;
	return make_pair(head,tail);
}

pair<Node*,Node*> pop(Node *key,Node *head,Node* tail)
{
	pair<Node*,Node*> k;
	if(head==key)
	{
		k=pop_front(head,tail);
		head=k.first;
		tail=k.second;
		return make_pair(head,tail);
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
	return make_pair(head,tail);
}


void display(Node* head,Node *tail)
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
int size(Node *head)
{
	int ret=0;
	for(Node* s=head;s!=NULL;s=s->next)
		ret++;
		
	return ret;
}


int main()
{
	int flag=1;
	Node *head,*tail;
	head=tail=NULL;
	char str[10];
	system("clear");
	while(flag)
	{
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
		pair<Node*,Node*> k;
		switch(n)
		{
			case 1:
					cout<<"Enter number to add:";
					cin>>inf;
					k=push_front(inf,head,tail);					
					head=k.first;
					tail=k.second;
					system("read -r -p 'Press enter to continue...' key");
					system("clear");
					break;
			case 2:
					cout<<"Enter number to add:";
					cin>>inf;
					k=push_back(inf,head,tail);					
					head=k.first;
					tail=k.second;
					system("read -r -p 'Press enter to continue...' key");
					system("clear");
					break;
			case 3:
					cout<<"Enter Number of node:";
					cin>>inf;
					if(inf==1)
					{
						if(head==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							k=push_front(inf,head,tail);					
							head=k.first;
							tail=k.second;
						}
					}
					else
					{
						int i,n=inf;
						Node *sp=NULL;
						n--;
						for(i=1,sp=head;i<n&&sp!=NULL;i++,sp=sp->next);
						if(i!=n||sp==NULL||sp->next==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							sp->next=NewNode(inf,sp->next);
						}
					}
					system("read -r -p 'Press enter to continue...' key");
					system("clear");
					break;
			case 4:
					cout<<"Enter Number of node:";
					cin>>inf;
					{
						int i,n=inf;
						Node *sp=NULL;
						for(i=1,sp=head;i<n&&sp!=NULL;i++,sp=sp->next);
						if(i!=n||sp==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							sp->next=NewNode(inf,sp->next);
							if(sp==tail)
								tail=sp->next;
						}
					}
					system("clear");
					break;
			case 5:
					k=pop_front(head,tail);					
					head=k.first;
					tail=k.second;
					system("read -r -p 'Press enter to continue...' key");
					system("clear");
					break;
			case 6:
					k=pop_back(head,tail);
					head=k.first;
					tail=k.second;
					system("read -r -p 'Press enter to continue...' key");
					system("clear");
					break;
			case 7:
					cin>>inf;
				{
					int i;
					Node *sp=NULL;
					for(i=1,sp=head;i<inf&&sp!=NULL;i++,sp=sp->next);
					if(i!=inf||sp==NULL)
						cout<<"Underflow!!\n";
					else
					{
						k=pop(sp,head,tail);					
						head=k.first;
						tail=k.second;
					}
				}
					system("read -r -p 'Press enter to continue...' key");
					system("clear");
					break;
				
			case 8:
					display(head,tail);
					system("read -r -p 'Press enter to continue...' key");
					system("clear");
					break;
			case 9:
					flag=0;
					cout<<"Bye\n";
					break;

		}		
	}
	return 0;
}
