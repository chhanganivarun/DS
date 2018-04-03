#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define SIZE 256
//2 2 4 6 6 7 1 2 5
string *cSort(string *a,int *b,int n,int curr)
{
	int cnt[SIZE];
	for(int i=0;i<SIZE;i++)
		cnt[i]=0;
	for(int i=0;i<n;i++)
	{
		cnt[a[i][min(b[i],curr)]]++;
	}
	for(int i=1;i<SIZE;i++)
	{
		cnt[i]+=cnt[i-1];
	}
	string sorted[n];
	for(int i=0;i<n;i++)
		sorted[i]="";
	for(int i=n-1;i>=0;i--)
	{
		sorted[cnt[a[i][min(b[i],curr)]]-1]=a[i];
		cnt[a[i][min(b[i],curr)]]--;
	}
	for(int i=0;i<n;i++)
	{
		a[i]=sorted[i];
	}
	return a;
}

int main()
{
	int n;
	n=7;
	string a[]={"14032018","20011876","23121947","28022000","01012012","08051934","16091999"};
	string t[]={"we","are","trying","to","sort","the","words"};
	int b[n];
	int maxim=0;
	for(int i=0;i<n;i++)
	{
		
		string t2="000";
		
		for(int j=0;t[i][j];j++)
		{
			int x=t[i][j];
			t2[0]=(x/100)%10+48;
			t2[1]=(x/10)%10+48;
			t2[2]=(x%10)+48;
			t2[3]='\0';
			a[i]+=t2;
		}
		cout<<a[i]<<"\n";
		
		b[i]=a[i].size();
		if(b[i]>maxim)
			maxim=b[i];
	}
	for(int exp=maxim;exp>=0;exp--)
	{
		cSort(a,b,n,exp);
			
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}
