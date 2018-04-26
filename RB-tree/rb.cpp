//Red Black tree isn't complete as of now
#include<bits/stdc++.h>
using namespace std;
#include"rb.h"
int main()
{
	Node *root=NULL;
	int flag=1;
	system("clear");
	while(flag)
	{
		cout<<"1. Insert to BST\n"
			<<"2. Print BST\n"
			<<"3. Delete Node\n"
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
					root=deleteNode(inf,root,root);
					break;
			case 4:
					flag=0;
					cout<<"Bye\n";
					break;
			case 5:
					root=check_violation(root,root);
					break;
		}
		system("read -r -p 'Press enter to continue...' key");
		system("clear");
	}

}
