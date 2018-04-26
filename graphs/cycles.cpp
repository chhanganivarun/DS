//To detect cycles in a graph
#include<bits/stdc++.h>
using namespace std;
std::vector<bool> visited;
int check_cycles(std::vector<std::vector<bool> > v,int n,int curr=-1)
{
    if(curr==-1)
        return check_cycles(v,n,0);

    if(visited[curr])
        return 0;

    int ret=false;
    visited[curr]=1;

    if(find(v[curr].begin(),v[curr].end(),true)==v[curr].end()&&find(visited.begin(),visited.end(),false)!=visited.end())
    {
        cout<<"Check for "<<find(visited.begin(),visited.end(),false)-visited.begin()<<endl;
        return check_cycles(v,n,(int)(find(visited.begin(),visited.end(),false)-visited.begin()));
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]&&v[curr][i])
            cnt++;
    }
    if(cnt>=2)
    {
        ret+=cnt-1;
    }


    for(int i=0;i<n;i++)
    {
        if(v[curr][i])
        {
            int x=check_cycles(v,n,i);
            ret+=x;
        }
    }
    return ret;
}
int main()
{
    cout<<"Enter number of nodes:";
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++)
        visited.push_back(0);
    cout<<"Enter no. of edges:";
    int e;
    std::cin >> e;
    
    std::vector<std::vector<bool> > v(n,std::vector<bool> (n));
    for(int i=0;i<e;i++)
    {
        int x,y;
        std::cin >> x>>y;
        v[x-1][y-1]=v[y-1][x-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cout<<v[i][j];
        std::cout  << '\n';
    }
    cout<<check_cycles(v,n)<<endl;
    return 0;
}
