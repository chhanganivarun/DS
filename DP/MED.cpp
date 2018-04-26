//Minimum Edit Distance
#include <bits/stdc++.h>
using namespace std;
std::vector<std::vector<int> > med_arr;
int MED(string a, string b,int m,int n,int subscost,int inscost,int delcost)
{
    if(!n)
        return m;
    if(!m)
        return n;

    if(med_arr[m-1][n-1]!=-1)
        return med_arr[m-1][n-1];

    if(a[m-1]==b[n-1])
        return med_arr[m-1][n-1]=MED(a,b,m-1,n-1,subscost,inscost,delcost);

    return med_arr[m-1][n-1]=min(MED(a,b,m-1,n,subscost,inscost,delcost)+inscost,min(MED(a,b,m-1,n-1,subscost,inscost,delcost)+subscost,MED(a,b,m,n-1,subscost,inscost,delcost)+delcost));
}
int main(int argc, char const *argv[]) {
    string a,b;
    cout<<"Enter first string:";
    cin>>a;
    cout<<"Enter second string:";
    cin>>b;
    int subscost,inscost,delcost;
    cout<<"Enter Substitution, Insertion and Deletion cost respectively:";
    cin>>subscost>>inscost>>delcost;
    int m=a.size(),n=b.size();
    for(int i=0;i<m;i++)
    {
        std::vector<int> temp;
        for(int j=0;j<n;j++)
            temp.push_back(-1);
        med_arr.push_back(temp);
    }
    cout<<MED(a,b,a.size(),b.size(),subscost,inscost,delcost)<<endl;
    //Uncomment following to see the matrix
    /*
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<med_arr[i][j]<<" ";
        cout<<endl;
    }
    */
    return 0;
}
