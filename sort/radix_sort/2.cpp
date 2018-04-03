#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define size 10
//2 2 4 6 6 7 1 2 5
float *cSort(float *a,int n,float exp)
{
	
	int cnt[size];
//	cout<<"n:"<<n<<"\n";
	for(int i=0;i<size;i++)
		cnt[i]=0;
//	cout<<"Counter array increments:\n";
	for(int i=0;i<n;i++)
	{
		cnt[((int)(a[i]*exp))%10]++;
//		cout<<((int)(a[i]*exp))%10<<" ";
	}
//	cout<<endl;
	for(int i=1;i<size;i++)
	{
		cnt[i]+=cnt[i-1];
	}
	float sorted[n];
	for(int i=0;i<n;i++)
		sorted[i]=-1;
	for(int i=n-1;i>=0;i--)
	{
		sorted[cnt[((int)(a[i]*exp))%10]-1]=a[i];
		cnt[((int)(a[i]*exp))%10]--;
	}
	for(int i=0;i<n;i++)
	{
//		cout<<"Copying "<<i<<"of"<<n<<" ";
		a[i]=sorted[i];
	}
	return a;
}

int main()
{
	int n;
	cin>>n;
	float a[n];
	float maxim=0;
	long long maxpow=1;
	for(int i=0;i<n;i++)
	{
//		cout<<"Enter no. "<<i<<":";
		cin>>a[i];
		
		while(a[i]*maxpow-((int)(a[i]*maxpow)))
		{
//			cout<<maxpow<<" "<<a[i]-(((int)(a[i]/maxpow))*maxpow)<<endl;
			maxpow*=10;
		}
		maxim=(maxim<a[i])?a[i]:maxim;
	}
//	cout<<maxpow<<"\n";
	

	for(double exp=(maxpow);floor(maxim*exp);exp/=10)
	{
//		printf("%f %d\n",exp,n);
		cSort(a,n,exp);
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
			
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
