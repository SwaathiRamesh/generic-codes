#include<iostream>
using namespace std;
struct node{
	char n; 
	node * next;
	};
// Have used an SLL here. Can be modified to use a DLL as well.
void insert_node( node *&head, char n)
{
	if(head==NULL)//head still not allocated
	{
//		cout<<" Head being assigned "<<endl;
		head = new ( node);
		head->n=n;
		head->next=NULL;
		return;
	}
	node *p=head;
	while(p->next)
		p=p->next;
	p->next=new(node);
	p=p->next;
	p->n=n;
	p->next=NULL;
}
void free_nodes(node *&head)
{
	cout<<" Freeing All nodes "<<endl;
	if(!head) { cout<<" no nodes "<<endl; return;}

	node *p=head;
	while(head)
	{
		p=head;
		head=head->next;
		delete(p);
	}
	head=NULL;
}
void display( node *head)
{	
	cout<<" Displaying All nodes "<<endl;
	node *p=head;
	if(!head) { cout<<" no nodes "<<endl; return;}
	while(p)
	{
		cout<<p->n<<endl;
		p=p->next;
	}

}
int compare( node *h1, node *h2)
{
	if(!h1) return -1;
	else if(!h2) return 1;
	node *p=h1, *q=h2;
	while(p && q)
	{
		if( p-> n != q->n ) return (p->n-q->n > 0)? 1: -1;
		else {
			p=p->next;
			q=q->next;
		}
	}
	if(!p && q) return -1;
	else if( p && !q) return 1;
	else if( !p && !q) return 0;
}
main()
{
int i;
node *h1=NULL, *h2=NULL;
cout<<"\n Enter the two strings:"<<endl;
string s;
cin>>s;
for(i=0;i<s.length();i++) insert_node(h1, s[i]);
cin>>s;
for(i=0;i<s.length();i++) insert_node(h2, s[i]);
display(h1);
display(h2);
cout<<"\n Result:\t"<<compare(h1,h2)<<endl;
free_nodes(h1);
free_nodes(h2);
}
