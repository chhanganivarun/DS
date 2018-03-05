#include<bits/stdc++.h>
using namespace std;

#include"pq.h"

int main()
{
	system("clear");
	int opt,flag=1;
	PriorityQueue q;
	string inf;
	while(flag)
	{
		cout<<"1. Push new Element in the priority queue\n"
			<<"2. Pop Element from front of queue\n"
			<<"3. Print elements in the queue\n"
			<<"4. Exit\n"
			<<"Enter Choice:";
		cin>>opt;
		switch(opt)
		{
			case 1:
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
					cout<<"In second mode:\n";
					q.display(cout);
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

