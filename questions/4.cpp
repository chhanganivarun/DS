int maxHeight(Node* root)
{
	if(!root)
		return 0;
	return max(maxHeight(root->left),maxHeight(root->right))+1;
}

bool checkSame(Node *root1,Node *root2)
{
	if(!root1&&!root2)
		return true;
	if(root1&&root2)
		return ((root1->data==root2->data)&&checkSame(root1->left,root2->left)&&checkSame(root1->right,root2->right));
	return false;
}

int diameter()
{
	;
}
int processdiameters()
{
	
}
