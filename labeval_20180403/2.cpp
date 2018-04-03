#include<bits/stdc++.h>
#include<stdio.h>
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

void bfs(Node *curr)
{
	Node* a[100];
	int start=0,end=0;
	a[end++]=curr;
	while(start!=end)
	{
		cout<<a[start]->data<<" ";
		if(a[start]->left)
			a[end++]=a[start]->left;
		if(a[start]->right)
			a[end++]=a[start]->right;
		start++;
	}

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

	cout<<"BFS:\n";
	bfs(curr);
	cout<<"\n";
}

bool check_bst(Node *root)
{
	if(!root)
		return true;
	if(root->left&&root->left->data>root->data)
		return false;
	if(root->right&&root->right->data<root->data)
		return false;
	return check_bst(root->left)&&check_bst(root->right);
		
}
Node *find(Node *root,int x)
{
	if(root==NULL)
		return NULL;
	if(root->data==x)
		return root;
	if(root->data<x)
		return find(root->right,x);
	return find(root->left,x);
}
void free_tree(Node *curr)
{
	if(curr->left)
		free_tree(curr->left);
	if(curr->right)
		free_tree(curr->right);
	delete curr;
}

bool search(int inf,Node* root)
{
	if(root==NULL)
		return false;
	if(root->data==inf)
		return true;
	if(inf>root->data)
		return search(inf,root->right);
	return search(inf,root->left);
}
int search(int *a,int s_idx,int e_idx,int key)
{
	for(int i=s_idx;i<e_idx;i++)
		if(a[i]==key)
			return i;
	return -1;
}
Node *make_tree(int *pre,int *in,int s_idx,int e_idx)
{
	if(s_idx>=e_idx)
		return NULL;
	
	static int precurr=0;
	
	int data=pre[precurr];
//	cout<<"For data="<<data<<" the precurr is:"<<precurr<<endl;	//Debug Note
	Node *ret=new Node;
	ret->data=data;
	
	int pos=search(in,s_idx,e_idx,data);
	if(pos==-1)
	{
		cout<<"An Error occured!!\nExiting.\n";
//		cout<<precurr<<" "<<s_idx<<" "<<e_idx<<" "<<data<<endl; //Debug Note
		exit(0);
	}
	precurr++;
	ret->left=make_tree(pre,in,s_idx,pos);
	ret->right=make_tree(pre,in,pos+1,e_idx);
	
	return ret;
	
}

int main()
{
	int n;
	cout<<"Enter number of inputs:";
	cin>>n;
	Node *tree=NULL;
	cout<<"Enter "<<n<<" integers in pre order sequence:";
	for(int i=0;i<n;i++)
	{
		int inf;
		cin>>inf;
		tree=push(inf,tree);
	}
	
	print(tree);
	cout<<endl;	
	free_tree(tree);
	return 0;
}
