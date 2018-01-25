#include<iostream>
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

	Node *prev=ll.head,*s=ll.head->next;
	int flag=0;
	for(prev=ll.head;prev->next!=NULL;)
	{
		flag=0;
		for(s=prev->next;s!=NULL;s=s->next)
		{
			if(s->data+prev->data==0)
			{
				ll.pop(s);
				ll.pop(prev);
				flag=1;
				break;
			}
		}
		if(!flag)
			prev=prev->next;
	}
	ll.display();
	return 0;
}
