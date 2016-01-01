#include<iostream>
using namespace std;
struct node{
	int n; 
	node * next;
	};
// Have used an SLL here. Can be modified to use a DLL as well.
void insert_node( node *&head, int n)
{
	if(head==NULL)//head still not allocated
	{
		cout<<" Head being assigned "<<endl;
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
void merge_sorted( node *h1, node *h2, node * &h3)
{
	node *p=h1, *q=h2;
	h3=new(node);
	if(!p) { h3->n=q->n; q=q->next; h3->next=NULL;}
	else if (!q) { h3->n=p->n; p=p->next; h3->next=NULL;}
	else
	{
		if(p->n> q->n) {
			h3->n=q->n;
			q=q->next;
			h3->next=NULL;
		}
		else
		{
			h3->n=p->n;
			p=p->next;
			h3->next=NULL;
		}
	}
	while( p && q)
	{
		if(p->n > q->n )
		{
			node *q1=new(node);
			q1->n=q->n;
			q=q->next;
			q1->next=h3;
			h3=q1;
		}
		else
		{
			node *p1=new(node);
			p1->n=p->n;
			p=p->next;
			p1->next=h3;
			h3=p1;
		}
	}
	while(p)
	{

			node *p1=new(node);
			p1->n=p->n;
			p=p->next;
			p1->next=h3;
			h3=p1;

	}
	while (q)
	{

			node *q1=new(node);
			q1->n=q->n;
			q=q->next;
			q1->next=h3;
			h3=q1;

	}

	
}
main()
{
int i;
node *h1=NULL, *h2=NULL;
// h1: 5->10->15
insert_node(h1, 5);
insert_node(h1,10);
insert_node(h1,15);
insert_node(h2,2);
insert_node(h2,3);
insert_node(h2,20);
cout<<" A before merge"<<endl;
display(h1);
cout<<" B before merge"<<endl;
display(h2);
node *h3=NULL;
merge_sorted(h1,h2,h3);
cout<<" Merged list"<<endl;
display(h3);
free_nodes(h1);
free_nodes(h2);
free_nodes(h3);


}
