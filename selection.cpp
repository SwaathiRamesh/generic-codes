#include<iostream>
using namespace std;
void print_array( int A[], int n)
{
	int i;
	cout<<"\n printing Array :\n";
	for(i=0;i<n;i++) cout<<A[i]<<" ";
}
void selection_sort(int A[], int n)
{
	int i,small=A[0];
	for(i=0;i<n;i++)
	{
		small=A[i];
		int j,pos=i;//A[pos]--smallest so far
		for(j=i+1;j<n;j++)
		{
			if(A[pos]>A[j])
			{
				pos=j;
			}
				
		}
		j=A[pos];
		A[pos]=A[i];
		A[i]=j;

	}
	cout<<"\n Array Sorted !";
}
main()
{
	int n;
	cout<<"\n Hpw many elements:\t";
	cin>>n;
	int A[n],i;
	cout<<"\n Enter elements: ";
	for(i=0;i<n;i++) cin>>A[i];
	print_array(A,n);
	selection_sort(A,n);
	print_array(A,n);
}


