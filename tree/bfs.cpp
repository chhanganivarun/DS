#include<iostream>
#include<bits/stdc++.h>
//#include"heap.h"

using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	Node *tree;
	root=make_tree(a,n);
	vector<pair<Node,int> > que;
	que.push_back(make_pair(root,1));
	int quepos=0;
	int curr=1;
	cout<<"[";
	while(!que.isEmpty)
	{
		Node *n=que[quepos].first;
		if(curr!=que[quepos].second)
		{
			curr=que[quepos];
			cout<<"],[";
		}
		cout<<n->data<<" ";
		if(n->left)
			que.push_back(make_pair(n->left,que[quepos]+1));
		if(n->right)
			que.push_back(make_pair(n->right,que[quepos]+1));
		quepos++;
	}
	cout<<"]\n";
}
