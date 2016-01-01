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
node * reverse( node *p)
{
	node *prev, *cur, *next;
	prev=p;cout<<"\n Prev "<<p->n<<endl;
	cur=p->next; cout<<" Cur:\t"<<cur->n<<endl;
	next=cur->next;cout<<" Next:\t"<<next->n<<endl;
	prev->next=NULL;
	cur->next=prev;
	prev=cur;
	cur=next;
	next=next->next;
	while(next)
	{
		cout<<"\n P: "<<prev->n<<"\t Cur: "<<cur->n<<"\t Next: "<<next->n<<endl;
		cur->next=prev;
		prev=cur;
		cur=next;
		next=next->next;
	}
	cur->next=prev;

	p=cur;
	cout<<"\n Inside function";
	display(p);
	return p;
}

node * node_sort( node *head)
{
	node *h=new(node);
	node *h1=h,*q;
	node *mid;
	node *p=head; int u=1;
	h->n=head->n;
	while(p)
	{

		if(p->next && p->next->next)
		{
			cout<<"\n For "<<p->next->next->n;
			h->next=new(node);
			p=p->next->next;
			h=h->next; h->n=p->n;
			h->next=NULL;

		}
		else p=NULL;
			
	}
	cout<<"\n Enting at "<<h->n<<endl;
	p=head->next;
	h->next=new(node);
	mid=h->next;
	h=h->next;
	h->n=p->n;
	h->next=NULL;
	while(p)
	{
		if(p->next && p->next->next)
		{
		h->next=new(node);
		p=p->next->next;
		h->next->n=p->n;
		h=h->next;
		}
		else p=NULL;
		
	}
	h->next=NULL;
	mid=h1;
	p=h1;
	int i=0;
	while(p)
	{
		p=p->next;
		if(i%2==0) { q=mid; mid=mid->next;}
		i++;
	}
	display(h1);
	cout<<"\n Reversing from "<<mid->n<<endl;
	mid=reverse(mid);
	q->next=mid;
	cout<<"\n After reversal "<<endl;
	display(h1);
	return h1;
}
main()
{
int i;
node *head=NULL;
for(i=1;i<=10;i++)
{
	if((i%2)) insert_node( head, i);
	else insert_node(head, 100-i);
}
display(head);
cout<<"\n SOrting it now"<<endl;
display( node_sort( head));
free_nodes(head);
display(head);
}
