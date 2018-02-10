#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,*a;
	cin>>n;
	a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				swap(min,j);
			}
		}
		swap(a[min],a[i]);
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;	
}
