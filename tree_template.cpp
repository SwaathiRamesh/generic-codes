#include<iostream>
using namespace std;
struct node{
	int n;
	node *left, *right;
};
void insert( node * &root, int n)
{
	if(!root)
	{
		root=new(node);
		root->n=n;
		root->left=root->right=NULL;
		return;
	}
	node *p=root, *q=root;
	int side=0;//1-left, 2-right
	while(p)
	{
		if(p->n > n ) {
			q=p;
			p=p->left;
			side=1;
		}
		else
		{
			q=p;
			p=p->right;
			side=2;
		}
	}
	switch(side)
	{
		case 1: // to be inserted on left
			q->left=new(node);
			q=q->left;
			q->n=n;
			q->left=q->right=NULL;
			break;
		case 2: // to be inserted on right
			q-> right= new(node);
			q=q->right;
			q->n=n;
			q->right=q->left=NULL;
	}
}
void display( node * r)
{
	if(!r) return;
	display(r->left);
	cout<<r->n<<endl;
	display(r->right);
}
int find_node( node *root, int n)
{
	node *p=root;
	while(p)
	{
		if(p->n > n) {p=p->left;}
		else if (p->n < n ) p=p->right;
		else return 1;
	}
	return 0;
}
void del_tree( node * &root)
{
	if(!root) return;
	del_tree(root->left);
	del_tree(root->right);
	delete(root); root=NULL;
}

int main()
{
	node *root=NULL;
	int i;
	for(i=1;i<=10;i++)
		if(i%2)insert( root, 100-i);
		else insert(root, 10*i+22);
	display(root);
	cout<<"\n Finding if a values exists in the tree: 44, 120"<<endl;
	if(find_node(root, 44))
		cout<<"\n FOund 44"<<endl;
	else cout<<"\n Not found 44"<<endl;
	if(find_node(root, 120))
		cout<<"\n Found node 120"<<endl;
	else cout<<"\n Not found node 120"<<endl;
	cout<<"\n Deleting tree "<<endl;
	del_tree(root);
	display(root);
}

