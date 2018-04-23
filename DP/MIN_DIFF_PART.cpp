// Divide given set in two parts s.t. difference between sum of the two sets is Minimum.
#include <bits/stdc++.h>
using namespace std;

std::vector<int> a;
std::vector<std::vector<bool> > diff;

void get_soln(int n,int max,int curr)
{
    if(curr>=n)
        return ;
    for(int i=0;i<=max;i++)
    {
        if(diff[curr-1][i])
            diff[curr][abs(i-a[curr])]=diff[curr][abs(i+a[curr])]=1;
    }
    get_soln(n,max,curr+1);
}
int main(int argc, char const *argv[]) {
    int n;
    cin>>n;


    std::vector<bool> temp(n);
    int max=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
        max+=abs(x);
        //diff.push_back(temp);
    }
    for(int j=0;j<=max;j++)
        temp[j]=0;

    for(int j=0;j<n;j++)
        diff.push_back(temp);

    diff[0][a[0]]=1;
    get_soln(n,max,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=max;j++)
        {
            cout<<diff[i][j]<<" ";
        }
        cout<<endl;

    }
    for(int i=0;i<=max;i++)
    {
        if(diff[n-1][i])
        {
            cout<<"Minimum found partition difference is "<<i<<endl;
            break;
        }
    }
    return 0;
}
