
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    getchar();
    for(int a0=0;a0<t;a0++)
    {
        string a,b;
        getline(cin,a);
        getline(cin,b);
        if(a.size()!=b.size())
        {
            cout<<"False\n";
            continue;
        }
        int n1=a.size();
        int n2=b.size();
        unordered_set<char> first;
        unordered_set<char> second;
        for(int i=0;i<n1;i++)
        {
            first.insert(a[i]);
            second.insert(b[i]);
        }
        bool found=true;
        for(char x:first){
            if(second.find(x)==second.end())
            {
                cout<<"False\n";
                found=false;
                break;
            }
        }
        if(found)
        {
            cout<<"True\n";
        }
    }
}
