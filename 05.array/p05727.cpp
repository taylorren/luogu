#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> v;

    while(n!=1)
    {
        v.push_back(n);
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=3*n+1;
        }
    }

    v.push_back(1);

    reverse(v.begin(),v.end());
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    
    return 0;
}