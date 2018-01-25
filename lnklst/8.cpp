#include<bits/stdc++.h>
using namespace std;
#include"ll.h"
int main()
{
	int n;
	LinkedList ll;
	cout<<"Enter number of integers in the linked list:";
	cin>>n;
	if(n>0)
		cout<<"Enter "<<n<<" integers:";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ll.push_back(x);
	}
	cout<<"\nCurrently the Linked List is:"<<endl;
	ll.display();
	if(ll.head==NULL)
	{
		cout<<"Empty List!!\nAborting!!\n";
		return -1;
	}

	int a[n];

	for(int i=0;i<n;i++)
		a[i]=0;
	int minlist=ll.min();
	for(Node *s=ll.head;s;s=s->next)
	{
		if(a[s->data-minlist]==0)
			a[s->data-minlist]=1;
	}
	for(Node *s=ll.head;s;s=s->next)
	{
		if(a[s->data-minlist]==1||a[s->data-minlist]==0)
			a[s->data-minlist]=2;
		else if(a[s->data-minlist]==2)
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]==0)
				{
					s->data=minlist+i;
					a[i]=2;
					break;
				}
			}
		}
	}
	ll.display();

	return 0;
	
}
