// singly linked list - insert, delete from various points
#include<iostream>
using namespace std;
struct node{
	int num;
	node * next;
};
void print_nodes(node *p)
{
	node *q=p;
	while(q)
	{
		cout<<q->num<<" ";
		q=q->next;
	}
}

main()
{
	node *head;
	head =new(node);
	head->num=10;
	head->next=NULL;
	print_nodes(head);
	
	//inserting at end
	node *p=new(node);
	p->num=90;
	p->next=NULL;
	head->next=p;
	cout<<endl;
	print_nodes(head);
	
	//inserting at beginning
	node *p1=new(node);
	p1->num=17;
	p1->next=head;
	head=p1;
	cout<<endl;
	print_nodes(head);
	
	//inerting at middle
	node *p2=new(node);
	p2->num=12;
	p2->next=head->next;
	head->next=p2;
	cout<<endl;
	print_nodes(head);
	
	//delete between
	node *p3=head->next;
	head->next=head->next->next;
	delete(p3);
	cout<<endl;
	print_nodes(head);

	//delete end
	node *p4=head;
	while(p4->next->next !=NULL) p4=p4->next;
	node *p5=p4->next;
	p4->next=NULL;
	delete(p5);
	cout<<endl;
	print_nodes(head);
	
	//delete beginning
	node *p6=head;
	head=head->next;
	delete(p6);
	cout<<endl;
	print_nodes(head);

	//deleting all dyn allocated pointers	
	delete(head);
	delete(p);
	delete(p1);
	delete(p2);
}
