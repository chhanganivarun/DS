#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,*a;
	cin>>n;
	a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int flag=1;
	for(int i=0;flag&&i<n-1;i++)
	{
		flag=0;
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				flag=1;
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;	
}
