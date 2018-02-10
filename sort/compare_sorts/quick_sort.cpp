#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,*a;
	n=100000;
	a=new int [n];
	for(int i=0;i<n;i++)
		a[i]=rand();
	sort(a,a+n);
	cout<<"Sorted!\n";
	return 0;
}
