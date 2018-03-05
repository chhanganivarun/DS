/****************************************************
find such arrangment of an array such that 
sum(|a[i]-a[i-1]|) is minimum.

find the total number of swaps required to achieve 
this.

****************************************************/

#include<iostream>
using namespace std;

vector<long> li;
vector<long> ld;
vector<long> a;
long LIS(long i)
{
    if(li[i]!=-1)return li[i];
    long res=1;
    for(long j=0;j<i;j++)
    {
        if(a[j]<a[i])
            res=max(res,1+LIS(j));
    }
    li[i]=res;
    return res;
 
}

long LDS(long i)
{
    if(ld[i]!=-1)return ld[i];
    long res=1;
    for(long j=0;j<i;j++)
    {
        if(a[j]>a[i])
            res=max(res,1+LDS(j));
    }
    ld[i]=res;
    return res;
 
}

int main()
{
	long n;
	cin>>n;
	
	vector<long> b(n);
	vector<long> c;
	
	for(long i=0;i<n;i++)
	{
		long x;
		cin>>x;
		li.push_back(-1);
		ld.push_back(-1);
		a.push_back(x);
		b[i]=a[i];
	}
	long lis=LIS(n-1);
	long lds=LDS(n-1);
	sort(b,b+n);
	sort(
	if(lis<=lds)
	{
		
	}
}
