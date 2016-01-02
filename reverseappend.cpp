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
node * delete_node( int n, node *&head)
{
	if(!head) return NULL;
	node *p=head, *prev;
	int y=0;
	while(p)
	{
		if(p->n==n)
		{
			y=1;
			if(p==head)
			{
				node *q=head;
				head=head->next;
				return q;
			}
			else
			{
				node *q=p;
				prev->next=q->next;
				return q;
			}
		}
		prev=p;
		p=p->next;
	}
	if(!y) cout<<"\n Element not found !";
}
void rev_add( node *&h, node *&p)
{
	if(h)
	cout<<"\n Head at "<<h->n<<" value to be added "<<p->n<<endl;
	else 
	cout<<"\n NULL node, value to be added is "<<p->n<<endl;
	if(!h )
	{ 
	 	cout<<"\n This is life "<<endl;
		h=p;
		cout<<"\n This too";
		h->next=NULL;
		cout<<"\n Now going "<<endl;
		return;
	}
	p->next=h;
	h=p;
	cout<<"\n Inside rev, displayin"<<endl;
	display(h);
}
main()
{
int i;
node *head=NULL;
for(i=0;i<10;i++)
	insert_node(head,2*i+42);
display(head);
cout<<"\n Now deletng "<<endl;

node *p=head, *newhead=NULL;
i=1;
while(p->next)
{	
	cout<<"\n At "<<p->n<<endl;
	node *r=p->next;
	if(i%2==0 )
	{
		cout<<"\n\t\t Even "<<endl; 
		node *p1=delete_node(p->n,head);
		cout<<"\n Node deleted "<<p1->n<<endl;
		rev_add(newhead, p1);
		cout<<"\n Continuing "<<endl;
//		rev_add( newhead, delete_node(p->n, head));
	}
	i++;
	cout<<"\n i value updated "<<endl;
	p=r;
	cout<<"\n Next iter "<<endl;
}
p->next= newhead;


display(head);
free_nodes(head);
display(head);
}
