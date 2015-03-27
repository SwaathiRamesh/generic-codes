#include<iostream>
using namespace std;
struct node{
	int i;
	node *next;
};
int main()
{
	int cnt=10;
	node *head=new(node);
	head->i=cnt++;
	head->next=NULL;
	node *p=head;
	cout<<"\n Before insert";
	while(cnt<10)
	{

		p->next=new(node);
		p=p->next;
		p->i=cnt;
		cnt++;
		p->next=NULL;
	}
	p->next=head->next;
	node *slo, *fast;
	slo=head; fast=head;
	while( slo!=NULL && fast !=NULL)
	{	cout<<"\n running ";
		if(slo==fast)
		{
			cout<<"\n Loop at "<< slo->i;
			slo=NULL;
		}
		else
		{
			slo=slo->next;
			fast=fast->next->next;
		}
	}
}
