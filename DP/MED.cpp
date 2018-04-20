//Minimum Edit Distance
#include <bits/stdc++.h>
using namespace std;
std::vector<std::vector<int> > med_arr;
int MED(string a, string b,int m,int n)
{
    if(!n)
        return m;
    if(!m)
        return n;

    if(med_arr[m-1][n-1]!=-1)
        return med_arr[m-1][n-1];

    if(a[m-1]==b[n-1])
        return med_arr[m-1][n-1]=MED(a,b,m-1,n-1);

    return med_arr[m-1][n-1]=1+min(MED(a,b,m-1,n),min(MED(a,b,m-1,n-1),MED(a,b,m,n-1))    );
}
int main(int argc, char const *argv[]) {
    string a,b;
    cin>>a>>b;
    int m=a.size(),n=b.size();
    for(int i=0;i<m;i++)
    {
        std::vector<int> temp;
        for(int j=0;j<n;j++)
            temp.push_back(-1);
        med_arr.push_back(temp);
    }
    cout<<MED(a,b,a.size(),b.size())<<endl;
    return 0;
}
