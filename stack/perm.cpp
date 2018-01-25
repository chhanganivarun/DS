#include<iostream>
using namespace std;
#include"stck.h"

bool ispossible(string sin,string sout)
{
	int n1=sin.length();
	int n2=sout.length();
	Stack Sin,Sout;
	for(int i=n1-1;i>=0;i--)
		Sin.push(sin[i]);
	for(int i=n2-1;i>=0;i--)
		Sout.push(sout[i]);
	Stack T;
	while(!Sin.isEmpty())
	{
		char temp=Sin.pop();
		if(temp==Sout.top->data)
		{
			Sout.pop();
			while(!T.isEmpty())
			{
				if(T.top->data==Sout.top->data)
				{
					T.pop();
					Sout.pop();
				}
				else
					break;
			}
			
		}
		else
		{
			T.push(temp);
		}
		
	}
	return T.isEmpty()&&Sin.isEmpty();
}


int main()
{
	string sin,sout;
	cout<<"Enter inital string:";
	getline(cin,sin);
	cout<<"Enter final string:";
	getline(cin,sout);
	if(ispossible(sin,sout))
	{
		cout<<"Possible!\n";
	}
	else
		cout<<"Not Possible!\n";
}
