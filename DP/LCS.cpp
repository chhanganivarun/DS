//Largest common substring
#include <bits/stdc++.h>
using namespace std;
std::vector<std::vector<int> > lcs_arr;
int lcs(string a,std::string b,int m,int n)
{
    if(!m||!n)
        return 0;
    if(lcs_arr[m-1][n-1]!=-1)
        return lcs_arr[m-1][n-1];
    if(a[m-1]==b[n-1])
        return lcs_arr[m-1][n-1]=1+lcs(a,b,m-1,n-1);
    return lcs_arr[m-1][n-1]=max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
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
        lcs_arr.push_back(temp);
    }
    cout<<lcs(a,b,a.size(),b.size())<<endl;
    return 0;
}
