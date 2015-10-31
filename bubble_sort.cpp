#include<iostream>
using namespace std;
void bubble( int A[], int n)
{
	int i,j,k;
	for(i=0,j=n-1;i<n && j>0;i++,j--)
	{
		cout<<"\n Iteration "<<i;
		for(k=0;k<j ;k++)
		{
			cout<<"\n\t Iteration "<<i<<"."<<k<<":";
			if(A[k]>A[k+1])
			{
				cout<<"\n\t\t Swapping "<<A[k]<<" and "<<A[k+1];
				int l=A[k];
				A[k]=A[k+1];
				A[k+1]=l;
			}
		}
			
	}
}
main()
{
	cout<<"\n Bubble Sort \n------------------\n Enter the number of elements :\t";
	
	int n=5,i;
	cin>>n;
	int A[n];
	cout<<"\n Enter the elements:";
	for(i=0;i<n;i++) cin>>A[i];
	cout<<"\n Initial Array:\n";
	for(i=0;i<n;i++)
	cout<<A[i]<<" ";
	bubble(A,n);
	cout<<"\n Sorted Array:\n";
	for(i=0;i<n;i++)
		cout<<A[i]<<" ";
}
