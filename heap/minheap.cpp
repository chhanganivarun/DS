#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
	a+=b;
	b=a-b;
	a=a-b;
}

int main()
{
	int flag=1;
	int last=1;
	int a[101];
	system("clear");
	while(flag)
	{
		cout<<"1. Push to heap\n"
			<<"2. Pop from heap\n"
			<<"3. Print heap\n"
			<<"4. Exit\n";
		cout<<"Enter Choice:";
		int n,inf,k;
		cin>>n;
		switch(n)
		{
			case 1:
					if(last==101)
					{
						cout<<"Can't add more!\n";
						break;
					}
					cout<<"Enter number to add:";
					cin>>inf;
					a[last]=inf;
					k=last;
					while(k!=0)
					{
						if(a[k]>=a[k/2])
						{
							break;
						}
						swap(a[k],a[k/2]);
						k/=2;
					}
					last++;					
					break;
			case 2:
					if(last==1)
					{
						cout<<"Underflow!!\n";
						break;
					}
					cout<<a[1]<<" has been popped.\n";
					last--;
					
					for(int i=2;i<=last;i++)
					{
						a[i-1]=a[i];	
						k=i-1;
						while(k!=0)
						{
							if(a[k]>=a[k/2])
							{
								break;
							}
							swap(a[k],a[k/2]);
							k/=2;
						}
					}
					break;
			case 3:
					for(int i=1;i<last;i++)
					{
						cout<<a[i]<<" ";
					}
					cout<<endl;
					break;
			case 4:
					flag=0;
					cout<<"Bye\n";
					break;

		}		
		system("read -r -p 'Press enter to continue...' key");
		system("clear");
	}

}
