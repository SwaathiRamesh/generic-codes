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
int max( int a, int b)
{
	int y= (a>b)? a: b;
	cout<<"\n\t\t Choosing "<<y<<endl;
	return y;
}
int maxsum( node *p, node *q)
{
	int sum=0;
	while(p && q)
	{
		if(p->n==q->n)
		{
			cout<<"\n Similarity at "<<p->n<<endl;			
			int y=max( maxsum(p->next, q), maxsum(q->next,p));
			cout<<"\n return"<<sum+y<<endl;
			return sum+y;

		}
		else
		{
			sum+=p->n;
			cout<<"\n Sum now is "<<sum<<endl;
			p=p->next;
			q=q->next;
		}
	}
	while(p)
	{
		sum+=p->n;
		p=p->next;
	}
	while(q)
	{
		sum+=q->n;
		q=q->next;
	}
	return sum;
}
main()
{
int i;
node *h1=NULL, *h2=NULL;
/*
 * List1 =  1->3->30->90->120->240->511
 * List2 =  0->3->12->32->90->125->240->249
 */
insert_node(h1, 1);
insert_node(h1, 3);
insert_node(h1, 30);
insert_node(h1, 90);
insert_node(h1, 120);
insert_node(h1, 240);
insert_node(h1, 511);
insert_node(h2, 0);
insert_node(h2, 3);
insert_node(h2, 12);
insert_node(h2, 32);
insert_node(h2, 90);
insert_node(h2, 125);
insert_node(h2, 240);
insert_node(h2, 249);
cout<<"\n List A"<<endl;
display(h1);
cout<<"\n List B"<<endl;
display(h2);
cout<<"\n Max Sum is "<<maxsum(h1,h2);
free_nodes(h1);
free_nodes(h2);
display(h1);
display(h2);
}
