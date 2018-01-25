#include<iostream>
using namespace std;
int main()
{
	string s[2];
	getline(cin,s[0]);
	int len=s[0].size();
	s[1]=string("");
	char temp[2]="";
	temp[1]=0;
	for(int i=len-1;i>=0;i--)
    {
        temp[0]=s[0][i];
        s[1]+=string(temp);
    }
    s[1][len]=0;
    cout<<s[1]<<"\n";
    int flag=1;
    for(int i=0;i<len&&flag;i++)
    {
        if(s[0][i]!=s[1][i])
            flag=0;
    }
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";
	return 0;
}
