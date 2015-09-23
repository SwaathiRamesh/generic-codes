#include<iostream>
using namespace std;
struct node {
	int n;
	node *next;} *head;
void insert( int n)
{
	node *p=head;
	while(p->next)
	p=p->next;
	p->next=new(node);
	p=p->next;
	p->n=n;
	p->next=NULL;
}
void print()
{
	node *r=head;
	while(r)
	{
		cout<<r->n<<endl;
		r=r->next;
	}
}
void reverse( node *prev, node*cur)
{
	if(!prev || ! cur)
		return;
	reverse(cur, cur->next);
	cur->next=prev;
}
int main()
{
	head=new(node);
	head->n=8;
	head->next=NULL;
	insert(9);
	insert(11);
	insert(90);
	insert(120);
	print();
	node *p=head;
	while(p->next) p=p->next;
	reverse(head, head->next);
	head->next=NULL;
	head=p;
	print();
	return 0;
}
