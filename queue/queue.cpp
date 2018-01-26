#include<bits/stdc++.h>
using namespace std;

#include"q.h"

int main()
{
	system("clear");
	int opt,flag=1;
	Queue q;
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
					q.push(inf);
					break;
			case 2:
					if(q.size())
						cout<<q.pop()<<" has been popped\n";
					else
						q.pop();
					break;
			case 3:
					q.display();
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

