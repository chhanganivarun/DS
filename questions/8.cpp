/******
Out of n people boarding an airplane, (in the order 1->n),
The first passenger doesn't sit in his assigned seat.
Calculate the probability of which passenger n (the last passenger)
sits in his assigned seat.
*******/
#include <bits/stdc++.h>
using namespace std;
long long fact(int n)
{
    return n<=0?1:n*fact(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n-1)-fact(n-2)<<"/"<<fact(n)-fact(n-1)<<endl;
    return 0;
}
