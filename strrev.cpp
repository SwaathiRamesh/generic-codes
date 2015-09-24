#include<iostream>
#include<string.h>
using namespace  std;
int main()
{ 	
	char s[100];
	int i, j, len;
	cout<<"\n Enter string to be reversed\t";
	cin>>s;
	len= strlen(s);
	for(i=0, j=len-1; i<j; i++, j--)
	{
		char p=s[i];
		s[i]=s[j];
		s[j]=p;
	}
	cout<<"\n Reversed string:\t"<<s<<endl;
}

