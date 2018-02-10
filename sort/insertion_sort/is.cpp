#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,*a;
	cin>>n;
	a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int x=a[i];
		int j=i-1;
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;	
}
