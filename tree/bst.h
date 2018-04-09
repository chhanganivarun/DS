struct Node{
	int data;
	Node *parent;
	Node *left;
	Node *right;
};
Node *push_next(Node *n,Node* curr,Node *root);
int height(Node *curr);
Node *NewNode();
Node *NewNode(int inf);
Node* push(int inf,Node *root);
Node *push_next(Node *n,Node* curr,Node *root);
Node *smallest(Node *curr);
void InOrder(Node *curr);
void PreOrder(Node *curr);
void PostOrder(Node *curr);
void PrintTree(Node* curr);
void bfs(Node *curr);
void print(Node *curr);
bool check_bst(Node *root);
Node *find(int x,Node *root);
bool search(int inf,Node* root);
void free_tree(Node *curr);
Node* deleteNode(Node *curr,Node *root);
Node* deleteNode(int inf,Node *curr,Node *root);

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
Node *smallest(Node *curr)
{
	if(curr->left)
		return smallest(curr->left);
	return curr;
}
void InOrder(Node *curr)
{
	if(curr==NULL)
		return;
	InOrder(curr->left);
	cout<<curr->data<<" ";
	InOrder(curr->right);
}
Node* deleteNode(int inf,Node *curr,Node *root)
{
	if(!find(inf,curr))
		return root;
	//cout<<"Found node "<<find(inf,curr)->data<<"\n";
	return deleteNode(find(inf,curr),root);
}
Node* deleteNode(Node *curr,Node *root)
{
	if(!curr)
		return NULL;
	if(curr->left&&curr->right)
	{
		//cout<<"Both children ";
		int replace=smallest(curr->right)->data;
		curr=deleteNode(replace,curr,curr);
		curr->data=replace;
		return root;
	}
	else if(curr->left)
	{
		//cout<<"Has Left child ";
		Node* ret=curr->parent;
		if(curr->parent)
		{
			//cout<<"Has parent ";
			if(curr->parent->left==curr)
			{
				curr->parent->left=curr->left;
				//cout<<"Left of parent\n";
			}
			else
			{
				curr->parent->right=curr->left;
				//cout<<"Right of parent\n";
			}

			ret=root;
		}
		else
		{
			ret=curr->left;
			//cout<<"No parent\n";
		}

		curr->left->parent=curr->parent;

		delete curr;
		return ret;
	}
	else if(curr->right)
	{
		//cout<<"Has Right child ";
		Node *ret;
		if(curr->parent)
		{
			//cout<<"Has parent ";
			if(curr->parent->left==curr)
			{
				curr->parent->left=curr->right;
				//cout<<"Left of parent\n";
			}
			else
			{
				curr->parent->right=curr->right;
				//cout<<"Right of parent\n";
			}
			ret=root;
		}
		else
		{
			ret=curr->right;
			//cout<<"No parent\n";
		}
		curr->right->parent=curr->parent;
		delete curr;
		return ret;
	}
	else
	{
		//cout<<"No child ";
		Node *ret;
		if(curr->parent)
		{
			//cout<<"Has parent ";
			if(curr->parent->left==curr)
			{
				curr->parent->left=NULL;
				//cout<<"Left of parent\n";
			}
			else
			{
				curr->parent->right=NULL;
				//cout<<"Right of parent\n";
			}
			ret=root;
		}
		else
		{
			ret=curr->right;
			//cout<<"No parent\n";
		}
		delete curr;
		return ret;
	}

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

void PrintTree(Node* curr)
{
	if(!curr)
		return ;
	pair<Node*,int> a[2048];
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
							cout<<"    ";
	  }
	  if(a[start].first)
	  {
		cout<<a[start].first->data;
		int size_data=log10(abs(a[start].first->data)?abs(a[start].first->data):1);
		if(a[start].first->left)
		  a[end++]=make_pair(a[start].first->left,a[start].second+1);
		else
		  a[end++]=make_pair((Node *)NULL,a[start].second+1);
		if(a[start].first->right)
		  a[end++]=make_pair(a[start].first->right,a[start].second+1);

		else
		  a[end++]=make_pair((Node *)NULL,a[start].second+1);

	  for(int i=0;i<8*space-size_data;i++)
		cout<<" ";

	  }
	  else
	  {

		a[end++]=make_pair((Node *)NULL,a[start].second+1);
		a[end++]=make_pair((Node *)NULL,a[start].second+1);
		for(int i=0;i<2*space;i++)
			cout<<"    ";
	  }
	  start++;
	}
}
void bfs(Node *curr)
{
	if(!curr)
		return ;
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
	if(curr)
		cout<<"Root:"<<curr->data<<"\n";
	cout<<"Tree:\n";
	PrintTree(curr);
	cout<<"\n";

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
Node *find(int x,Node *root)
{
	if(root==NULL)
		return NULL;
	if(root->data==x)
		return root;
	if(root->data<x)
		return find(x,root->right);
	return find(x,root->left);
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
