#include<iostream>
using namespace std;
#include"cll.h"

int main()
{
	int n;
	LinkedList ll;
	cout<<"Enter number of chars in Linked List:";
	cin>>n;
	if(n>0)
		cout<<"Enter "<<n<<" chars:";
	for(int i=0;i<n;i++)
	{
		char x;
		cin>>x;
		ll.push_back(x);
	}
	cout<<"Current list:";
	ll.display();
	cout<<"Enter positions of nodes to be reversed (1-"<<ll.size()<<"):";
	int x,y;
	cin>>x>>y;
	Node *a,*b;
	a=ll.return_index(x);
	b=ll.return_index(y);
	if(a==NULL||b==NULL)
	{
		return 0;
	}
	char temp;
	temp=a->data;
	a->data=b->data;
	b->data=temp;
	cout<<"\nThe Updated Linked List is:"<<endl;
	ll.display();
	return 0;
}
