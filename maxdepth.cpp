// Maxdepth- O(n)
#include<iostream>
using namespace std;
struct node{
	int n;
	node *left, *right;
} *root;
int height( node *root)
{
	if(root==NULL) return 0;
	int l=height(root->left);
	int r=height(root->right);
	return( 1+((l>r)?l:r));
}
int main()
{
	root=new(node);
	root->n=1;
	root->right=new(node);
	root->right->n=3;
	root->right->left=root->right->right=NULL;
	root->left=new(node);
	node *p=root->left;
	p->n=2;
	p->left=new(node);
	p->right=new(node);
	p->left->n=4;
	p->left->left=p->left->right=NULL;
	p->right->n=5;
	p->right->left=p->right->right=NULL;

	cout<<"\n Height of NULL:\t"<<height(NULL);	
	cout<<"\n Height of root:\t"<<height(root);
}

