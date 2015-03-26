#include<iostream>
using namespace std;
int fact(int x)
{
	if (x==1 || x==0) return 1;
	else return (x)*fact(x-1);
}

main()
{
	int i;
	cout<<"\n factorial of which number?:\t";
	cin>>i;
	cout<<"\n factorial of "<<i<<" is "<<fact(i);
}

