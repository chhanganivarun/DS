#include<bits/stdc++.h>
using namespace std;
#include"stck.h"

int main()
{
	system("clear");
	int opt,flag=1;
	Stack s;
	while(flag)
	{
		cout<<"1. Push new Element on the stack\n"
			<<"2. Pop Element from top of stack\n"
			<<"3. Print elements in the stack\n"
			<<"4. Exit\n"
			<<"Enter Choice:";
		cin>>opt;
		switch(opt)
		{
			case 1:
					int inf;
					cout<<"Enter data to insert on the stack:";
					cin>>inf;
					s.push(inf);
					break;
			case 2:
					if(s.size())
						cout<<s.pop()<<" has been popped\n";
					else
						s.pop();
					break;
			case 3:
					s.print();
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


