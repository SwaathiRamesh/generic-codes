#include<iostream>
using namespace std;
struct list_node{
	int n;
	list_node *next;
	};
struct graph_node{
	list_node *start;
};
void list_insert( graph_node *G, int x, int y)
{
	
	list_node *p= G[x].start;
	if(!p)
	{

		G[x].start=new(list_node);
		p=G[x].start;
		p->n=y;
		p->next=NULL;

	}
	else{

	while(p->next !=NULL)
		p=p->next;
	p->next=new(list_node);
	p=p->next;
	p->n=y;
	p->next=NULL;}
	while(0){
	cout<<"\n\t Status now:\n\t";
	p=G[x].start;
	while(p)
	{ cout<<p->n<<","; p=p->next;}
	cout<<endl;}
}

void graph_display( graph_node *G, int vertices, int edges)
{
	int i;
	list_node *p;
	for(i=0;i<vertices;i++)
	{
		p=G[i].start;
		cout<<"\n for "<<i<<" : ";
		while(p)
		{
			cout<<p->n<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}

main()
{
	int num_of_vertices, num_of_edges,i;
	cout<<"\n How many vertices?:\t";
	cin>>num_of_vertices;
	cout<<"\n How many edges?:\t";
	cin>>num_of_edges;
	cout<<"\n Vertices are number as 0 to"<<num_of_vertices-1;
	graph_node G[num_of_vertices];
	for(i=0;i<num_of_vertices;i++) G[i].start=NULL;
	cout<<"\n Enter the edges in order:\n";
	for(i=0;i<num_of_edges;i++)
	{
		int a,b;
		cout<<"\n Edge "<<i+1<<" : ";
		cin>>a>>b;
		list_insert(G,a,b);
		list_insert(G,b,a);
		
	}
	graph_display(G, num_of_vertices, num_of_edges);
}
	
