#include<iostream>
using namespace std;
#include"ll.h"

int main()
{
	int n1,n2;
	LinkedList ll1,ll2;
	cout<<"Enter number of integers in first set:";
	cin>>n1;
	if(n1>0)
		cout<<"Enter "<<n1<<" integers:";
	for(int i=0;i<n1;i++)
	{
		int x;
		cin>>x;
		ll1.push_back(x);
	}
	cout<<"Enter number of integers in second set:";
	cin>>n2;
	if(n2>0)
		cout<<"Enter "<<n2<<" integers:";
	for(int i=0;i<n2;i++)
	{
		int x;
		cin>>x;
		ll2.push_back(x);
	}
	
	for(Node *s=ll1.head;s!=NULL&&s->next!=NULL;s=s->next)
	{
		for(Node *p=s->next;p!=NULL;p=p->next)
		{
			if(s->data==p->data)
			{
				ll1.pop(p);
			}
		}
	}
	for(Node *s=ll2.head;s!=NULL&&s->next!=NULL;s=s->next)
	{
		for(Node *p=s->next;p!=NULL;p=p->next)
		{
			if(s->data==p->data)
			{
				ll2.pop(p);
			}
		}
	}	
	cout<<"\nCurrently the first set is:"<<endl;
	ll1.display();
	cout<<"\nCurrently the second set is:"<<endl;
	ll2.display();
	
	LinkedList ll3;
	for(Node *s=ll1.head;s!=NULL;s=s->next)
	{
		ll3.push_back(s->data);
	}
	for(Node *s=ll2.head;s!=NULL;s=s->next)
	{
		ll3.push_back(s->data);
	}
	for(Node *s=ll3.head;s!=NULL&&s->next!=NULL;s=s->next)
	{
		for(Node *p=s->next;p!=NULL;p=p->next)
		{
			if(s->data==p->data)
			{
				ll3.pop(p);
			}
		}
	}	
	cout<<"\nUnion of sets is:"<<endl;
	ll3.display();

	for(Node *s=ll3.head;s!=NULL;s=ll3.head)
	{
		ll3.pop_back();
	}

	for(Node *s=ll2.head;s!=NULL;s=s->next)
	{
		int flag=0;
		for(Node *p=ll1.head;p!=NULL&&!flag;p=p->next)
		{
			if(s->data==p->data)
				flag=1;
		}
		if(flag)
		{
			ll3.push_back(s->data);
		}
	}
	cout<<"\nIntersection of sets is:"<<endl;
	ll3.display();
	
	return 0;
	
}
