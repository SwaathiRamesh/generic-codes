#include<iostream>
using namespace std;
main()
{
	cout<<"\n We will be showing insertion sort here. Please enter the number of integers to be sorted ";
	int n;
	cin>>n;
	int Arr[n], i, j;
	for(i=0;i<n;i++) cin>>Arr[i];
	cout<<"\n Now, we are sorting the array. At each stage, we assume that the initial part of the array is already sorted and then we keep adding the newly encountered elements\n ";

	for(j=1;j<n;j++)
	{
		
	cout<<"\n Initially, sorted array:\t";
	for(i=0;i<j;i++) cout<<Arr[i]<<" ";
	cout<<"\n\t Now adding "<<Arr[j]<<" to the sorted part ";
		for(i=j;i>0;i--)
			if(Arr[i]<Arr[i-1])
			{	
				cout<<"\n\t\t Swapping "<<Arr[i]<<" and "<<Arr[i-1];
				int k=Arr[i];
				Arr[i]=Arr[i-1];
				Arr[i-1]=k;
			}
	}
	cout<<"\n Sorted array:\n";
	for(i=0;i<n;i++)
		cout<<Arr[i]<<" ";
	cout<<endl;
}


	

