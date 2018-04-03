#include<bits/stdc++.h>
using namespace std;
#include"bst.h"

int main()
{
	Node *root=NULL;
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		int inf;
		cin>>inf;
		root=push(inf,root);
	}
	for(int i=0;i<m;i++)
	{
		int inf;
		cin>>inf;
		if(search(inf,root))
		{
			cout<<inf<<" is present in the tree!\n";
		}
		else
			cout<<inf<<" is NOT present in the tree!\n";
		
	}
}
