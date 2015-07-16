//Are they Identical - O(n)
#include<iostream>
using namespace std;
struct node{
	int n;
	node *left, *right;}*root1, *root2;
int areSame(node *root1, node *root2)
{
	if(root1==NULL && root2==NULL) return 1;
	else if (root1==NULL || root2==NULL) return 0;
	return ((root1->n==root2->n)? (1&&areSame(root1->left,root2->left)&&areSame(root1->right,root2->right)): 0);
}	
main()
{
	root1=new(node);
	root1->n=1;
	root1->right=new(node);
	root1->right->n=3;
	root1->right->left=root1->right->right=NULL;
	root1->left=new(node);
	node *p=root1->left;
	p->n=2;
	p->left=new(node);
	p->right=new(node);
	p->left->n=4;
	p->left->left=p->left->right=NULL;
	p->right->n=5;
	p->right->left=p->right->right=NULL;
	root2=NULL;
	cout<<"\n Root1 and NULL:\t"<<areSame(root1,root2);
	cout<<"\n NULL and root2:\t"<<areSame(NULL,root2);
	cout<<"\n root1 and root1:\t"<<areSame(root1,root1);	


}
