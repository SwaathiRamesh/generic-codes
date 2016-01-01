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
void delete_node( int n, node *&head)
{
	if(!head) return;
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
				delete(q);
			}
			else
			{
				node *q=p;
				prev->next=q->next;
				delete(q);
			}
		}
		prev=p;
		p=p->next;
	}
	if(!y) cout<<"\n Element not found !";
}

main()
{
int i;
node *head=NULL;
for(i=0;i<10;i++)
	insert_node(head,2*i+42);
display(head);
cout<<"\n Deleting 48"<<endl;
delete_node(48, head);
display(head);
free_nodes(head);
display(head);
}
