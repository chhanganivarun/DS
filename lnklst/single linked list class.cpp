#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#include"ll.h"

int main()
{
	int flag=1;
	LinkedList ll;
	char str[10];
	system("clear");
	while(flag)
	{
		ll.display();
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
		switch(n)
		{
			case 1:
					cout<<"Enter number to add:";
					cin>>inf;
					ll.push_front(inf);					
					break;
			case 2:
					cout<<"Enter number to add:";
					cin>>inf;
					ll.push_back(inf);					
					break;
			case 3:
					cout<<"Enter Number of node:";
					cin>>inf;
					if(inf==1)
					{
						if(ll.head==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							ll.push_front(inf);					
						}
					}
					else
					{
						int i,n=inf;
						Node *sp=NULL;
						n--;
						for(i=1,sp=ll.head;i<n&&sp!=NULL;i++,sp=sp->next);
						if(i!=n||sp==NULL||sp->next==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							sp->next=ll.NewNode(inf,sp->next);
						}
					}
					break;
			case 4:
					cout<<"Enter Number of node:";
					cin>>inf;
					{
						int i,n=inf;
						Node *sp=NULL;
						for(i=1,sp=ll.head;i<n&&sp!=NULL;i++,sp=sp->next);
						if(i!=n||sp==NULL)
						{
							cout<<"Underflow!!\n";
						}
						else
						{
							cout<<"Enter number to add:";
							cin>>inf;
							sp->next=ll.NewNode(inf,sp->next);
							if(sp==ll.tail)
								ll.tail=sp->next;
						}
					}
					break;
			case 5:
					ll.pop_front();					
					break;
			case 6:
					ll.pop_back();
					break;
			case 7:
					cin>>inf;
					ll.popindex(inf);
					break;
				
			case 8:
					ll.display();
					break;
			case 9:
					flag=0;
					cout<<"Bye\n";
					break;

		}
		if(n<9&&n>0)
		{
			system("read -r -p 'Press enter to continue...' key");
			system("clear");
		}
	}
	return 0;
}


