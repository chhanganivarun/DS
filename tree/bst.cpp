#include<bits/stdc++.h>
using namespace std;
#include"bst.h"


int main()
{
	Node *root=NULL;
	Node *np;
	int flag=1;
	system("clear");
	while(flag)
	{
		cout<<"1. Insert to BST\n"
			<<"2. Print BST\n"
			<<"3. Delete\n"
			<<"4. Exit\n";
		cout<<"Enter Choice:";
		int n,inf;
		cin>>n;
		switch(n)
		{
			case 1:
					cout<<"Enter number to add:";
					cin>>inf;
					root=push(inf,root);					
					break;
			case 2:
					print(root);
					cout<<endl;
					break;
			case 3:
					cout<<"Enter number to delete:";
					cin>>inf;
					np=find(root,inf);
					if(n)
					{
						cout<<"Under Construction!\n";
					}
					else
						cout<<"Node not found!\n";
					break;
			case 4:
					flag=0;
					cout<<"Bye\n";
					break;

		}		
		system("read -r -p 'Press enter to continue...' key");
		system("clear");
	}

}
