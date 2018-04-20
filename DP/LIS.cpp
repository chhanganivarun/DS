#include <bits/stdc++.h>
using namespace std;
std::vector<int> lis;
int LIS(std::vector<int> a,int m)
{
    if(m<0)
        return 0;
    if(lis[m]!=-1)
        return lis[m];
    int maxlis=1;
    for(int i=0;i<m;i++)
    {
        maxlis=max(maxlis,LIS(a,i)+(a[i]<a[m]));
    }
    return lis[m]=maxlis;
}
int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        lis.push_back(-1);

    std::vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<LIS(a,n-1)<<endl;
    return 0;
}
