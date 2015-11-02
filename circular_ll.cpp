#include<iostream>
using namespace std;
struct node{
	int n;
	node *next;
	int mark;
} *start, *end;
void add_elt( int n)
{
	if(!start) {
		start =new(node);
		end=start;
		start->n=n; start->mark=0;
		start->next=start; return;}
	node *p=new(node);
	end->next=p;
	end=end->next;
	end->n=n; end->mark=0;
	end->next=start;
}

void display()
{
	if(!start) cout<<"\n Empty Queue"<<endl;
	node *p=start;
	cout<<"\n Displaying elts now "<<endl;
	while(p!=end)
	{
		cout<<p->n<<" ";
		p=p->next;
	}
	cout<<p->n<<endl;
}
int delete_elt( node *p)
{
	cout<<"\n Delete_node called on "<<p->n<<endl;
	node *q=start;
	if(q==p)
	{
		if(start->next==start) { cout<<"\n The last one standing is "<<start->n<<endl; return -1;}
		cout<<"\n\t Deleting "<<q->n<<endl;
		start=start->next;
		end->next=start; return 0;
	}
	while(q->next != p)
	{
		q=q->next;
	}
	cout<<"\n\t Deleting "<<q->next->n<<endl;
	q->next=q->next->next;
	return 0;

}
int main()
{
	start=end=NULL;
	add_elt(1);
	add_elt(2);
	add_elt(3);
	add_elt(4);
	add_elt(5);
	add_elt(6);
	display();
	cout<<"\n now, we delete every 2nd element till there is only one left "<<endl;
	int n=1, ret=0;
	node *p=start;
	while(!ret)
	{
		++n;
		p=p->next;
		if(n%2==0) ret=delete_elt(p);
	}

}
