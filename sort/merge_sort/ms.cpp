#include<bits/stdc++.h>
using namespace std;
int *merge(int *a,int start,int mid,int end)
{
	int n=end-start;
	int c[n];
	int curr_a=start,curr_b=mid,curr_c=0;
	int n_a=mid,n_b=end;
	while(curr_a<n_a&&curr_b<n_b)
	{
		if(a[curr_a]<a[curr_b])
		{
			c[curr_c]=a[curr_a++];
			curr_c++;
		}
		else
		{
			c[curr_c]=a[curr_b++];
			curr_c++;
		}
	}
	while(curr_a<n_a)
	{
		c[curr_c]=a[curr_a++];
		curr_c++;

	}
	while(curr_b<n_b)
	{
		c[curr_c]=a[curr_b++];
		curr_c++;
	}
	for(int curr_c=0;curr_c<n;curr_c++)
	{
		a[start+curr_c]=c[curr_c];
	}
	
}

void mergesort(int *arr,int start,int end)
{
	int n=end-start;
	int mid=start+n/2;
	if(n<=1)
		return ;
		
	
	mergesort(arr,start,mid);
	mergesort(arr,mid,end);

	merge(arr,start,mid,end);

	cout<<endl;

}

int main()
{
	int n;
	cout<<"Enter number of integer inputs:";
	cin>>n;
	int a[n];
	cout<<"Enter an array of "<<n<<" integers:";
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	mergesort(a,0,n);
	cout<<"\nMerged array is:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
