#include<bits/stdc++.h>
using namespace std;
int *merge(int *a,int n_a,int *b,int n_b)
{
	int *c=new int [n_a+n_b];
	int curr_a=0,curr_b=0,curr_c=0;
	for(int curr_c=0;curr_c<n_a+n_b;)
	{
		if(curr_a<n_a && curr_b<n_b && a[curr_a]<=b[curr_b])
		{
			c[curr_c++]=a[curr_a++];
		}
		else if(curr_a<n_a && curr_b<n_b && a[curr_a]>b[curr_b])
		{
			c[curr_c++]=b[curr_b++];
		}
		else if(curr_a>=n_a)
		{
			c[curr_c++]=b[curr_b++];
		}
		else if(curr_b>=n_b)
		{
			c[curr_c++]=a[curr_a++];
		}
		else
		{
			cout<<"NC\n";
			cout<<a[curr_a]<<":"<<b[curr_b]<<":"<<c[curr_c]<<":\n";
			++curr_c;
		}
	}
	cout<<"\r";
	delete []a;
	delete []b;
	return c;
}

int *mergesort(int *arr,int n)
{
	if(n<=1)
		return arr;
	
	int mid=n/2;
	int *a=new int[mid];
	int *b=new int[n-mid];
	for(int i=0;i<mid;i++)
	{
		a[i]=arr[i];
	}
	for(int i=0;i<n-mid;i++)
	{
		b[i]=arr[mid+i];
	}
	
	a=mergesort(a,mid);
	b=mergesort(b,n-mid);
	int *c= merge(a,mid,b,n-mid);
	return c;
}

int main()
{
	int n;
	cout<<"Enter number of integer inputs:";
	cin>>n;
	int *a=new int[n];
	cout<<"Enter an array of "<<n<<" integers:";
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	int *c=mergesort(a,n);
	cout<<"\nMerged array is:";
	for(int i=0;i<n;i++)
		cout<<c[i]<<" ";
	cout<<endl;
	delete []a;
	delete []c;
	return 0;
}
