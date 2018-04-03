#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *parent;
	Node *left;
	Node *right;
};
Node *push_next(Node *n,Node* curr,Node *root);	
Node *NewNode()
{
	Node *n=new Node;
	n->left=n->right=n->parent=NULL;
	return n;
}
Node *NewNode(int inf)
{
	Node *n=NewNode();
	n->data=inf;
	return n;
}
Node* push(int inf,Node *root)
{
	Node *n=NewNode(inf);
	if(root==NULL)
	{
		root=n;
	}
	else
		push_next(n,root,root);
	return root;
}
Node *push_next(Node *n,Node* curr,Node *root)
{
	if(n->data<curr->data)
	{
		if(curr->left==NULL)
		{
			curr->left=n;
			curr->left->parent=curr;
		}
		else
			return push_next(n,curr->left,root);
	}
	else
	{
		if(curr->right==NULL)
		{
			curr->right=n;
			curr->right->parent=curr;
		}
		else
			return push_next(n,curr->right,root);
	}
	return root;
}

void InOrder(Node *curr)
{
	if(curr==NULL)
		return;
	InOrder(curr->left);
	cout<<curr->data<<" ";
	InOrder(curr->right);
}
void PreOrder(Node *curr)
{
	if(curr==NULL)
		return;
	cout<<curr->data<<" ";
	PreOrder(curr->left);
	PreOrder(curr->right);
}
void PostOrder(Node *curr)
{
	if(curr==NULL)
		return;
	PostOrder(curr->left);
	PostOrder(curr->right);
	cout<<curr->data<<" ";
}

void print(Node *curr)
{
	cout<<"In Order:\n";
	InOrder(curr);
	cout<<endl;
	
	cout<<"Pre Order:\n";
	PreOrder(curr);
	cout<<endl;
	
	cout<<"Post Order:\n";
	PostOrder(curr);
	cout<<endl;
	
}
int main()
{
	Node *root=NULL;
	int flag=1;
	system("clear");
	while(flag)
	{
		cout<<"1. Insert to BST\n"
			<<"2. Print BST\n"
			<<"3. Exit\n";
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
					flag=0;
					cout<<"Bye\n";
					break;

		}		
		system("read -r -p 'Press enter to continue...' key");
		system("clear");
	}

}
