#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<long long> a(n);
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int gap=n/2;gap>=1;gap--)
	{
		for(int i=gap;i<n;i+=gap)
		{
			int x=a[i];
			cout<<"check on "<<x<<endl;
			int j=i-gap;
			while(j>=0&&a[j]>x)
			{
				a[j+gap]=a[j];
				j-=gap;
			}
			a[j+gap]=x;
		}
		cout<<"For gap = "<<gap<<" the array is:";
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl<<endl;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}
