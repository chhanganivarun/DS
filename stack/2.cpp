#include<iostream>
using namespace std;
#include"stck.h"

char close(char ch)
{
	if(ch==')')
		return '(';
	else if(ch==']')
		return '[';
	else if(ch=='}')
		return '{';
	else return -1;

}
int main()
{
	Stack S;
	string str;
	cout<<"Input a bracket string:";
	getline(cin,str);
	int flag=1;
	for(int i=0;str[i]!=0&&flag;i++)
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')
		{
			S.push(str[i]);
		}
		else if(str[i]==')'||str[i]==']'||str[i]=='}')
		{
			if(S.isEmpty())
			{
				flag=0;
				break;
			}			
			char ch=S.pop();
			if(ch!=close(str[i]))
				flag=0;
		}
	}
	if(flag&&S.isEmpty())
		cout<<"Success!\n";
	else
		cout<<"Fail\n";
	return 0;
}
