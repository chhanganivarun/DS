#include<bits/stdc++.h>
using namespace std;
#define SIZE 100
void push(int *a,int data,int &n)
{
	if(n==SIZE)
	{
		cout<<"Overflow!!\n";
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>data)
		{
			for(int j=n;j>=i;j--)
				a[j]=a[j-1];
			a[i]=data;
			n++;
			return;
		}
	}
	a[n++]=data;
	
}

int pop(int *a,int &n)
{
	if(n<=0)
	{
		cout<<"Underflow!!\n";
		return -1;
	}
	int x=a[0];
	for(int i=1;i<n;i++)
	{
		a[i-1]=a[i];
	}
	n--;
	return x;
}

void display(int *a,int &n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<"->";
	cout<<":::\n";
}

int main()
{
	system("clear");
	int opt,flag=1;
	int q[SIZE];
	int n=0;
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
					push(q,inf,n);
					break;
			case 2:
					if(n)
						cout<<pop(q,n)<<" has been popped\n";
					else
						pop(q,n);
					break;
			case 3:
					display(q,n);
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

