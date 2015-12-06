#include<iostream>
using namespace std;
struct node{
	int n;
	node *next;
} *beg1, *beg2;
main()
{
	beg1=new(node);
	beg2=new(node);
	beg1->next=new(node);
	beg2->next=new(node);
	beg1->next->next=NULL;
	beg2->next->next=NULL;
	beg1->n=10;
	beg1->next->n=20;
	beg2->n=30;
	beg2->next->n=40;
	node *p=beg1;
	while(p->next!=NULL) p=p->next;
	p->next=beg2;
	p=beg1;
	while(p)
	{
		cout<<endl<<p->n;
		p=p->next;
	}
}
