#include<iostream>
using namespace std;
struct node{
	int n;
	node *left, *right;}*root;
void inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->n<<",";
	inorder(root->right);
}	
void root2leaf(node *q, int *A, int len)
{
	if(!q) return;
//	cout<<"\n For node "<<q->n<<endl;
	int i, leninside=len+1;
	int B[11];
	if((q->left==q->right) && q->left==NULL)
	{	cout<<"\n------PRINTNG PATH------\n";
		for(i=0;i<len;i++)
			cout<<A[i]<<",";
		cout<<q->n;
		return;
	}
	for(i=0;i<len;i++)
		B[i]=A[i];
	B[len]=q->n;
	if(q->left!=NULL) root2leaf(q->left, B, leninside);
	if(q->right !=NULL) root2leaf(q->right, B, leninside);
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
	p->left=p->right=NULL;
	p->left=new(node);
	p->right=new(node);
	p->left->n=4;
	p->left->left=p->left->right=NULL;
	p->right->n=5;
	p->right->left=p->right->right=NULL;
	cout<<"\n INORDER\n";
	inorder(root);
	int a[10];
	int len=1;
	a[0]=root->n;

	root2leaf(root->left, a,len);
	root2leaf(root->right, a ,len);
	
}

