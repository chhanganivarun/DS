#include<bits/stdc++.h>
using namespace std;
#include"../stack/stck.h"

int stckrevcpy(Stack &s1,Stack &s2)
{
	Stack s3;
	while(s1.top)
		s1.pop();
	while(s2.top)
	{
		int x=s2.pop();
		s1.push(x);
		s3.push(x);
	}
	while(s3.top)
		s2.push(s3.pop());
	return 1;
}

void print(Stack S)
{
	for(Node *sp=S.top;sp!=NULL;sp=sp->next)
		cout<<sp->data<<"->";
	cout<<":::\n";
}
int main()
{
	system("clear");
	Stack s1,s2;
	int opt,flag=1;
	while(flag)
	{
		cout<<"1. Push new Element at the end of queue\n"
			<<"2. Pop Element from front of queue\n"
			<<"3. Print elements in the queue\n"
			<<"4. Exit\n"
			<<"Enter Choice:";
		cin>>opt;
		switch(opt)
		{
			case 1:
					int inf;
					cout<<"Enter data to insert on the queue:";
					cin>>inf;
					s2.push(inf);
					stckrevcpy(s1,s2);
					break;
			case 2:
					if(s1.size())
					{
						cout<<s1.pop()<<" has been popped\n";
						stckrevcpy(s2,s1);
					}	
					else
						cout<<"Underflow\n";
					break;
			case 3:
					print(s1);
					break;
			case 4:
					cout<<"Bye\n";
					flag=0;
					break;
					
		}
		system("read -r -p 'Press enter to continue...' key");
		system("clear");
		
	}
	return 0;	
}

