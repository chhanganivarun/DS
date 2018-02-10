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
	int n,k,inf;
	int last=1;
	int a[101];
	cout<<"How many numbers to sort:";
	cin>>n;
	if(n>100)
	{
		cout<<"Overflow!!\n";
		return 0;
	}
	cout<<"Enter "<<n<<" numbers:";
	for(int i=0;i<n;i++)
	{
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
	}
	while(last!=1)
	{
		cout<<a[1]<<" ";
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
	}
	cout<<"\n";
	return 0;
}
