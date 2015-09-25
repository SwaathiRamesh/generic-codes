// Cracking the Coding Interview 5e Problem 1.5
#include<iostream>
using namespace std;
int main()
{
	string s,p;
	getline(cin,s);
	int i,j,len,p_len,p_i=0;
	for(i=0;s[i];i++);
	len=i;
	for(i=0;i<len;i++)
	{

			p[p_i++]=s[i];
			for(j=i;j<len && s[i]==s[j];j++);
			p[p_i++]='0'+(j-i);
			i=j-1;
	}

	p_len=p_i;
	if(p_len >= len) cout<<s;
	else
	for(i=0;i<p_len;i++) cout<<p[i];
}
			

