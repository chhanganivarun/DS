#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#include"bst.h"

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
	int pre[n];
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	cout<<"Enter "<<n<<" integers in in order sequence:";
	int in[n];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	tree=make_tree(pre,in,0,n);
	
	print(tree);
	
	free_tree(tree);
	return 0;
}
