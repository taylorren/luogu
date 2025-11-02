#include <bits/stdc++.h>
using namespace std;

const int MAX=200'010;

map<int, int> s;
int a[MAX];
int n, c;

int main()
{
    cin>>n>>c;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[a[i]]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=s[a[i]-c];
    }

    cout<<ans<<endl;
    return 0;
}