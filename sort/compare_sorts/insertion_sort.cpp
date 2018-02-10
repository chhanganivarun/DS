#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,*a;
	n=100000;
	a=new int [n];
	for(int i=0;i<n;i++)
		a[i]=rand();
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
	cout<<"Sorted!\n";
	return 0;
}
