#include<bits/stdc++.h>
using namespace std;
#define SIZE 100
void push(int *a,int *p,int data,int pri,int &n)
{
	if(n==SIZE)
	{
		cout<<"Overflow!!\n";
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(p[i]<pri)
		{
			for(int j=n;j>=i;j--)
			{
				a[j]=a[j-1];
				p[j]=p[j-1];
			}
			a[i]=data;
			p[i]=pri;
			n++;
			return;
		}
	}
	p[n]=pri;
	a[n]=data;
	n++;
	
}

pair<int,int> pop(int *a,int *p,int &n)
{
	if(n<=0)
	{
		cout<<"Underflow!!\n";
		return make_pair(-1,-1);
	}
	int x=a[0];
	int y=p[0];
	for(int i=1;i<n;i++)
	{
		a[i-1]=a[i];
		p[i-1]=p[i];
	}
	n--;
	return make_pair(x,y);
}

void display(int *a,int *p,int &n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<"->";
	cout<<":::\n";
	for(int i=0;i<n;i++)
		cout<<p[i]<<"->";
	cout<<":::\n";
}

int main()
{
	system("clear");
	int opt,flag=1;
	int q[SIZE];
	int p[SIZE];
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
					int inf,pri;
					cout<<"Enter data to insert on the queue:";
					cin>>inf;
					cout<<"Enter priority of the data:";
					cin>>pri;
					push(q,p,inf,pri,n);
					break;
			case 2:
					if(n)
					{
						pair <int, int> k=pop(q,p,n);
						cout<<k.first<<" of priority "<<k.second<<" has been popped\n";
					}
					else
						pop(q,p,n);
					break;
			case 3:
					display(q,p,n);
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

