#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,*a;
	n=100000;
	a=new int [n];
	for(int i=0;i<n;i++)
		a[i]=rand();
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
	cout<<"Sorted!\n";
	return 0;
}
