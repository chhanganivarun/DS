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
	int k;
	cout<<"Enter value of k:";
	cin>>k;
	cout<<"\nCurrently the Linked List is:"<<endl;
	ll.display();
	
	
	if(ll.head==NULL)
	{
		cout<<"Empty List!!\nAborting!!\n";
		return -1;
	}
	if(k<=0)
	{
		cout<<"k should be greater than 0\n";
		return -1;
	}
	
	
	LinkedList temp_ll,final_ll;
	
	while(ll.head)
	{
		int cnt=0;
		for(cnt=0;ll.head&&cnt<k;cnt++)
		{
			temp_ll.push_front(ll.pop_front());
		}
		while(temp_ll.head!=NULL)
		{
			final_ll.push_back(temp_ll.pop_front());
		}
	}
	
	cout<<"The proccessed Linked List is:\n";
	final_ll.display();
	return 0;
}
