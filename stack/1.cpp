#include<iostream>
using namespace std;
#include"stck.h"

int main()
{
	Stack S;
	string str;
	string str2="";
	cout<<"Input a string:";
	getline(cin,str);
	str+=" ";
	for(int i=0;str[i]!=0;i++)
	{
		if(str[i]==' ')
		{
			while(!S.isEmpty())
			{
				str2+=S.pop();
			}
			str2+=" ";
		}
		else
			S.push(str[i]);
	}
	cout<<str2<<"\n";
}
