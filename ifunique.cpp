#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
	cout<<"\n This code is for ASCII strings and for A-Z (26) characters\n";
	cout<<"\n This is assuming we can have extra space.";
	char s[100];
	bool DICT[26];
	int i;
	cout<<"\n Enter the string:\t";
	cin>>s;
	if(strlen(s) >26) {
		cout<<"\n Repetitions exist";
		exit(0);
	}
	for(i=0;i<26;i++)
	{	if(DICT[s[i]-'A'])
		{
			cout<<"\n Repetitions exist "<<s[i]<<endl;
			exit(0);
		}
		DICT[s[i]-'A']=1;
	}
}


	
