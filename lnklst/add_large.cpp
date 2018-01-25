#include<iostream>
#include<string.h>
struct Node{
	char data;
	Node *next;
	Node *prev;
};
//gaurav6696
Node *NewNode(char inf)
{
	Node *n=new Node;
	n->next=NULL;
	n->prev=NULL;
	n->data=inf;
}

Node *Insert_beg(Node *head,Node *n)
{
	n->next=head;
	if(head!=NULL)
		head->prev=n;
	head=n;
	return head;
}
using namespace std;
int main()
{
	char a[80],b[80];
	cin>>a>>b;
	int size_a=strlen(a);
	int size_b=strlen(b);
	
	if(size_a<size_b)
	{
		char c[80];
		strcpy(c,"");
		for(int i=0;i<size_b-size_a;i++)
			strcat(c,"0");
		strcat(c,a);
		strcpy(a,c);
	}
	if(size_a>size_b)
	{
		char c[80];
		strcpy(c,"");
		for(int i=0;i<size_a-size_b;i++)
			strcat(c,"0");
		strcat(c,b);
		strcpy(b,c);
	}
//	cout<<a<<"\n"<<b<<"\n";
	
	
	
	Node *head_a=NULL,*head_b=NULL;
	Node *head_c=NULL;
	int i,j;
	head_a=Insert_beg(head_a,NewNode(48));
	for(i=0;a[i]!=0;i++)
	{
		head_a=Insert_beg(head_a,NewNode(a[i]));
	}
	
	head_b=Insert_beg(head_b,NewNode(48));		
	for(j=0;b[j]!=0;j++)
	{
		head_b=Insert_beg(head_b,NewNode(b[j]));
	}
	/*
	for(Node *s=head_a;s!=NULL;s=s->next)
	{
		cout<<s->data;
	}
	cout<<"\n";
	*/
	/*
	for(Node *s=head_b;s!=NULL;s=s->next)
	{
		cout<<s->data;
	}
	cout<<"\n";
	*/
	
	
	
	int carry=0;
	Node *iter_a=head_a;
	Node *iter_b=head_b;
	
	for(int k=0;k<=i;k++)
	{
		if (k!=i)
		{
			head_c=Insert_beg(head_c,NewNode((iter_a->data+iter_b->data-(48*2)+carry)%10+48));
			carry=(iter_a->data+iter_b->data-(48*2)+carry)/10;
		}	
		else
		{
			head_c=Insert_beg(head_c,NewNode(carry+48));
		}
	//	cout<<head_c->data<<":"<<carry<<".";
		if(iter_a->next!=NULL)
				iter_a=iter_a->next;
		if(iter_b->next!=NULL)
			iter_b=iter_b->next;
	}
	cout<<"\n";

	for(Node* iter_c=head_c;iter_c!=NULL;iter_c=iter_c->next)
		cout<<iter_c->data;
	cout<<"\n";
	
	
}
