#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r;
    cin>>l>>r;
    int count=0;

    for(int i=l;i<=r;i++)
    {
        if(sqrt(i)==(int)sqrt(i))
        {
            count++;
        } 
    }

    cout<<count;

    return 0;
}