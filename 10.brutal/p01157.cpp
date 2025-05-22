#include <bits/stdc++.h>
using namespace std;

int a[30];

int main()
{
    int n, r;
    cin>>n>>r;
    for(int S=(1<<n)-1;S>=0;S--)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(S&(1<<i))
            {
                a[count++]=i;
            }
        }
        if(count==r)
        {
            for(int i=r-1;i>=0;i--)
            {
                cout<<setw(3)<<n-a[i];
            }
            cout<<endl;
        }
        
    }
    return 0;
}