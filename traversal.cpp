#include<iostream>
using namespace std;
struct node{
	int n;
	node *left, *right;}*root;
void inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<"\n"<<root->n;
	inorder(root->right);
}	
void preorder( node *root)
{
	if(root==NULL) return;
	cout<<"\n"<<root->n;
	preorder(root->left);
	preorder(root->right);
}	
void postorder( node *root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<"\n"<<root->n;
}
main()
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
	cout<<"\n INORDER";
	inorder(root);
	cout<<"\n PREORDER";
	preorder(root);
	cout<<"\n POSTORDER";
	postorder(root);
}
