// code for solution to Josephus problem
#include<iostream>
using namespace std;
int T[10][10];
int josephus(int n, int k)
{
	cout<<"\n\t in J("<<n<<","<<k<<")";
	if( n==1) return 1;
	int t= ((josephus(n-1,k)+k-1)%n+1);
	cout<<"\n \t Returning "<<t<<" in J("<<n<<","<<k<<")";
	return t;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int i,j;
	cout<<"\n The one that survives: "<<josephus(n,k);

}
