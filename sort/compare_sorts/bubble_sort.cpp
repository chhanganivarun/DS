#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,*a;
	n=95000;
	a=new int [n];
	for(int i=0;i<n;i++)
		a[i]=rand();
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
	cout<<"Sorted!\n";
	return 0;
}
