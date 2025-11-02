#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin>>n>>m;
    long long squ=0, rec=0;

    for(long long i=1;i<=min(n, m);i++)
    {
        squ+=(n-i+1)*(m-i+1);
    }

    rec=n*(n+1)*m*(m+1)/4-squ;

    cout<<squ<<" "<<rec<<endl;

    return 0;
}