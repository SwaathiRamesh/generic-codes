#include<iostream>
#include<string.h>
using namespace  std;
int main()
{ 	
	string s;;
	int i, j, len;
	cout<<"\n Enter string to be reversed\t";
	getline(cin,s);
	for(i=0;s[i];i++);
	len=i;
	if(s[0]=='\0')
	{
		cout<<"\n NULL string, eh?";
		cout<<"\n Reversed string:\t"<<s<<endl;
	}
	else
	{
	for(i=0, j=len-1; i<j; i++, j--)
	{
		char p=s[i];
		s[i]=s[j];
		s[j]=p;
	}
	cout<<"\n Reversed string:\t"<<s<<endl;
	}
}

