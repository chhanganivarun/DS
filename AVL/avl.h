struct Node{
	int data;
	Node *parent;
	Node *left;
	Node *right;
	int height;
};
Node *push_next(Node *n,Node* curr,Node *root);	
int height(Node *root);
Node *check_voilation(Node *root);
Node *NewNode()
{
	Node *n=new Node;
	n->left=n->right=n->parent=NULL;
	n->height=1;
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
	return push(inf,root,root);
}
Node* push(int inf,Node *root,Node *curr)
{
	Node *n=NewNode(inf);
	if(root==NULL)
	{
		root=n;
	}
	else
	{
		if(n->data<curr->data)
		{
			if(curr->left==NULL)
			{
				curr->left=inf;
				curr->left->parent=curr;
				Node *n=curr->parent;
			
			}
			else
			{
				return push(inf,root,curr->left);
			}
		}
		else
		{
			if(curr->right==NULL)
			{
				curr->right=inf;
				curr->right->parent=curr;
			}
			else
			{
				return push(inf,root,curr->right);
			}
		}
		return root;		
	}
	
	root=check_voilation(root);
	return root;
}
Node *push_next(Node *n,Node *root,Node *curr)
{
}

int height(Node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}

Node *smallest(Node *root)
{
	if(root==NULL)
		return NULL;
	if(root->left==NULL)
		return root;
	return smallest(root->left);
}
/*
Node *del(Node *root,Node *key)
{
	if(key->left==key->right&&key->left==NULL)
	{
		if(key==root)
		{
			delete key;
			root==NULL;
			return root;
		}
		if(key->parent->left==key)
			key->parent->left=NULL;
		else
			key->parent->right=NULL;
		
		delete key;
		return root;
	}
	if(key==root)
	{
		
	}
	if(key->left==NULL)
	{
		if(key->parent)
	}
	
	
}
*/
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

Node *check_voilation(Node *root)
{
	
}
