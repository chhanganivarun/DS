//To detect cycles in a graph
#include<bits/stdc++.h>
using namespace std;
std::vector<bool> visited;
bool check_cycles(std::vector<std::vector<bool> > v,int n,int curr=-1)
{
    if(curr==-1)
        return check_cycles(v,n,0);

    int cnt=0;
    for(int i=0;i<n&&curr<2;i++)
    {
        if(visited[i]&&v[curr][i])
            cnt++;
    }
    if(cnt>=2)
    {
        cout<<n<<" "<<curr<<"\n";
        return 1;
    }

    if(visited[curr])
        return 0;

    visited[curr]=1;
    bool ret=false;
    for(int i=0;i<n;i++)
    {
        if(v[curr][i])
        {
            bool x=check_cycles(v,n,i);
            ret=ret||x;
            cout<<n<<" "<<curr<<" "<<i<<" "<<x<<"\n";
        }
    }
    cout<<"At last:"<<curr<<" "<<ret<<endl;
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
    if(check_cycles(v,n))
        std::cout <<"True"<<endl;
    else
        std::cout << "False" << '\n';
}
