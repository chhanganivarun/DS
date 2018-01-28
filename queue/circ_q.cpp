#include<bits/stdc++.h>
using namespace std;
#define SIZE 100
void push(int *a,int data,int &front,int &rear)
{
	if((front==0&&rear==SIZE-1)||front==rear+1)
	{
		cout<<"Overflow!!\n";
		return ;
	}
	if(front==rear&&rear==-1)
	{
		front=rear=0;
		a[rear]=data;
		return ;
	}
	if(rear==SIZE-1)
	{
		rear=0;
		a[rear]=data;
		return;
	}
	rear++;
	a[rear]=data;
}

int pop(int *a,int &front,int &rear)
{
	if(front==-1)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	int x=a[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else if(front==SIZE-1)
	{
		front=0;
	}
	else
	{
		front+=1;
	}
	return x;
}

void display(int *a,int &front,int &rear)
{
	cout<<front<<":"<<rear<<"\n";
	if(front<=rear&&front>=0)
	{	
		for(int i=front;i<=rear;i++)
			cout<<a[i]<<"->";
	}
	else if(front!=-1)
	{
		for(int i=front;i<SIZE;i++)
			cout<<a[i]<<"->";
		for(int i=0;i<=rear;i++)
			cout<<a[i]<<"->";		
	}
	cout<<":::\n";
}

int main()
{
	system("clear");
	int opt,flag=1;
	int q[SIZE];
	int front=-1,rear=-1;
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
					int inf;
					cout<<"Enter data to insert on the queue:";
					cin>>inf;
					push(q,inf,front,rear);
					break;
			case 2:
					if(front!=-1)
						cout<<pop(q,front,rear)<<" has been popped\n";
					else
						pop(q,front,rear);
					break;
			case 3:
					display(q,front,rear);
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

