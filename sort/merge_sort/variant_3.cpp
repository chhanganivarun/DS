#include<bits/stdc++.h>
using namespace std;
int *merge(int *a,int start,int &mid,int end)
{
	int n=end-start,a_n=mid-start,b_n=end-mid;
	int acurr=0,bcurr=0;
	while(mid<end)
	{
		int j=mid-1;
		int temp=a[mid];
		while(j>=start&&a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;

		mid++;
	}
	//1 3 2 8 3 1 5 6 4 2
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
	cout<<"Merged array is:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
