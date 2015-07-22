#include<iostream>
using namespace std;
struct node{
	int n;
	node *left, *right;}*root;

void inorder( node *t)
{
	if (!t) return;
	inorder(t->left);
	cout<<t->n<<",";
	inorder(t->right);
}
void nodeadd( int n)
{
	if(root==NULL)
	{
		root=new(node);
		root->n=n;
		root->left=root->right=NULL;
		return;
	}
	node *p=root;
	node *q=p;
	int l=0;
	while(p)
	{	
		q=p;
		if(p->n>=n) {p=p->left;l=0;}
		else {p=p->right; l=1;}
	}
	if(l)
	{
		q->right=new(node);
		node *r=q->right;
		r->n=n;
		r->left=r->right=NULL;
	}
	else
	{
		q->left=new(node);
		node *r1= q->left;
		r1->n=n;
		r1->left=r1->right=NULL;
	}
}	
void printinterval( int k1, int k2, node *p)
{
	if(!p) return;
	//cout<<"\n for "<<p->n;
	if(p->n > k2) 
	{
		printinterval(k1,k2,p->left);
		return;
	}
	if(p->n <k1)
	{
		printinterval(k1,k2,p->right);
		return;
	}

	printinterval(k1,k2,p->left);
	if(p->n !=k1 && p->n != k2)
	cout<<p->n<<",";
	printinterval(k1,k2,p->right);
}	

main()
{
	int n, k1, k2;
	cout<<"\n how many nodes?\t";
	cin>>n;
	root=NULL;
	int num;
	while(n--)
	{	cout<<"\n enter the value:\t";
		cin>>num;
		nodeadd(num);
	}		
	inorder(root);
	cout<<"\n enter the lower range:\t";
	cin>>k1;
	cout<<"\n Enter the upper range:\t";
	cin>>k2;
	printinterval(k1,k2, root);

}	
