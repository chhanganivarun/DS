#include<bits/stdc++.h>
using namespace std;
int *merge(int *a,int start,int &mid,int end)
{
	int acurr=start,bcurr=mid;
	while(acurr<bcurr&&bcurr<end)
	{
//		cout<<acurr<<" "<<bcurr<<" ";
		if(a[acurr]>a[bcurr])
		{
//			cout<<"Yes\n";
			int x=a[bcurr];
			int i;
			for(i=bcurr-1;i>=acurr;i--)
			{
				a[i+1]=a[i];
				
			}
			a[i+1]=x;
/*
			for(int i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout<<endl;
*/
		}
		else
		{
//			cout<<"No\n";
			bcurr--;
		}
		acurr++;
		bcurr++;
	}
	//1 7 8 9 2 3 4
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
	
	
//	merge(a,0,t,n);
	mergesort(a,0,n);
	cout<<"Merged array is:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
