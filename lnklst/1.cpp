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
	
	Node *curr=ll.head;
	int curr_cond=0;
	for(Node *sp=ll.head->next;sp!=NULL;sp=sp->next)
	{
		curr_cond=1-curr_cond;
		if(!curr_cond)
		{
			curr=curr->next;
		}
	}
	cout<<"The Middle of the List is:"<<curr->data<<"\n";
	return 0;
}
