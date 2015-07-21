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
		if(cnt ==9)
		p->next=head->next;
		else p->next=NULL;

	}
	//cout<<"\n p's next newly: "<<p->next->i;
	node *slo, *fast;
	int o=0;
	slo=head; fast=head->next;
	while( slo!=NULL && fast !=NULL)
	{	cout<<"\n running ";
		if(slo==fast)
		{
			cout<<"\n Loop at "<< slo->i;
			break;
		}
		else
		{
			slo=slo->next;
			fast=fast->next->next;
		}
	}
	if (slo==NULL || fast ==NULL)
		cout<<"\n No loop";
}
