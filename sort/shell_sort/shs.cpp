#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,*a;
	cin>>n;
	a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int gap=n/2;gap>=1;gap--)
	{
		for(int i=gap;i<n;i+=gap)
		{
			int x=a[i];
			int j=i-gap;
			while(j>=0&&a[j]>x)
			{
				a[j+gap]=a[j];
				j-=gap;
			}
			a[j+gap]=x;
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}
