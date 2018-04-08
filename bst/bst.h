struct Node{
	int data;
	Node *parent;
	Node *left;
	Node *right;
};
Node *push_next(Node *n,Node* curr,Node *root);
int height(Node *curr)
{
	if(!curr)
		return 0;
	return max(height(curr->left),height(curr->right))+1;
}
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

void PrintTree(Node* curr,int offset=0)
{
	pair<Node*,int> a[100];
	int start=0,end=0;
	int currheight=-1;
	a[end++]=make_pair(curr,0);
	int h=height(curr);
	int space=pow(2,h);
	while(a[start].second<h)
	{
	  if(currheight!=a[start].second)
	  {
			currheight=a[start].second;
			space/=2;
	    cout<<"\n";
			for(int i=0;i<space;i++)
							cout<<"\t";
	  }
	  if(a[start].first)
	  {
	    cout<<a[start].first->data;

	    if(a[start].first->left)
	      a[end++]=make_pair(a[start].first->left,a[start].second+1);
	    else
	      a[end++]=make_pair((Node *)NULL,a[start].second+1);
	    if(a[start].first->right)
	      a[end++]=make_pair(a[start].first->right,a[start].second+1);

	    else
	      a[end++]=make_pair((Node *)NULL,a[start].second+1);

	  }
	  else
	  {
//			cout<<"NULL";
	    a[end++]=make_pair((Node *)NULL,a[start].second+1);
	    a[end++]=make_pair((Node *)NULL,a[start].second+1);
	  }
		for(int i=0;i<2*space;i++)
			cout<<"\t";
	  start++;
	}
}
void bfs(Node *curr)
{
	pair<Node*,int> a[100];
	int start=0,end=0;
	int currheight=0;
	a[end++]=make_pair(curr,0);
	while(start!=end)
	{
		if(currheight!=a[start].second)
		{
			cout<<",";
			currheight=a[start].second;
		}

		cout<<a[start].first->data<<" ";
		if(a[start].first->left)
			a[end++]=make_pair(a[start].first->left,a[start].second+1);
		if(a[start].first->right)
			a[end++]=make_pair(a[start].first->right,a[start].second+1);
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

	PrintTree(curr);
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
