#include<iostream>
using namespace std;
#include"ll.h"

int main()
{
	int n;
	LinkedList ll;
	cout<<"Enter number of integers in Linked List:";
	cin>>n;
	if(n>0)
		cout<<"Enter "<<n<<" integers:";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ll.push_back(x);
	}
	
	for(Node *s=ll.head;s!=NULL&&s->next!=NULL;s=s->next)
	{
		for(Node *p=s->next;p!=NULL;p=p->next)
		{
			if(s->data==p->data)
			{
				ll.pop(p);
			}
		}
	}
	cout<<"\nThe Linked List is:"<<endl;
	ll.display();
	return 0;
}
