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
void swap_nodes( node *&head, int a, int b)
{
	if(!head) return;
	node *p1,*p2,*n1,*n2, *b1, *d;
	int i=0,pos=0;
	if(head->n == a)
		i=2;
	      else if( head-> n ==b)
	i=1;
	p1=head;
	while(p1)
	{
		if(p1->n==a) pos=1;
		p1=p1->next;
	}
	if(!pos) { cout<<"\n"<<a<<" Not found"<<endl; return;}
	p1=head; pos=0;
	while(p1)
	{
		if(p1->n==b) pos=1;
		p1=p1->next;
	}
	if(!pos) {cout<<endl<<b<<" Not Found"<<endl; return;}

	cout<<"\n Beginnning"<<endl;
	p1=head;
	while(p1 && p1->next->n !=a && i!=2 )
	p1=p1->next;
	if(p1==NULL) { cout<<"\n"<<a<<" Not found"<<endl; return;}
	p2=head;
	while(p2->next->n !=b && i!=1 && p2)
	p2=p2->next;
	if(p2==NULL) {cout<<endl<<b<<" Not Found"<<endl; return;}
	if(i==2)
	b1=head;
	else
	b1=p1->next;
	if(i==1)
	d=head;
	else
	d=p2->next;
	n1=b1->next;
	n2=d->next;
	if(i!=2)
	p1->next=d;
	d->next=n1;
	if(i!=1)
	p2->next=b1;
	b1->next=n2;

	if(i==1)
	head= b1;
	else if (i==2)
		head=d;
	cout<<"\n Swapping over"<<endl;
	display(head);
	
}
	
main()
{
int i;
node *head=NULL;
for(i=0;i<10;i++)
	insert_node(head,2*i+42);
cout<<"\n Initial List"<<endl;
display(head);
cout<<"\n Base case for logic: Swapping 46 and 56"<<endl;
swap_nodes( head, 46, 56);
display(head);

cout<<"\n Case when one of the nodes is the head: Swapping 42 and 50"<<endl;
swap_nodes( head, 42, 50);
display(head);

cout<<"\n Case when the order is reversed:Swapping 5 and 48"<<endl;
swap_nodes( head, 58, 48);
display(head);

cout<<"\n Case when it is in end: 52 and 60";
swap_nodes( head, 52, 60);
display(head);

cout<<"\n Case when one of the numbers not present: 101 and 60";
swap_nodes( head, 101, 60);
display(head);

cout<<"\n Case when head and tail are swapped:";
swap_nodes(head,50,52);
display(head);

free_nodes(head);
display(head);
}
