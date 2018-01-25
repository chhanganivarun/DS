#include<iostream>
using namespace std;
#include"dll.h"

int main()
{
	int n;
	DoublyLinkedList dll;
	cout<<"Enter number of integers in the linked list:";
	cin>>n;
	if(n>0)
		cout<<"Enter "<<n<<" integers:";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		dll.push_back(x);
	}
	cout<<"Enter Sum of pairs:";
	int x;
	cin>>x;
	
	if(dll.head==NULL)
	{
		cout<<"Empty List!!\nAborting!!\n";
		return -1;
	}

	Node *prev=dll.head,*s=dll.head->next;
	for(prev=dll.head;prev->next!=NULL;prev=prev->next)
	{
		for(s=prev->next;s!=NULL;s=s->next)
		{
			if(s->data+prev->data==x)
			{
				cout<<"("<<s->data<<","<<prev->data<<")\n";
			}
		}
	}
	return 0;
}
