#include <bits/stdc++.h>
using namespace std;
int n, fa[200005], ans = 0x3f3f3f, cnt;
int find(int x)
{
    ++cnt;
    return (fa[x] == x ? x : find(fa[x]));
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1, t; i <= n; cnt = 0, i++)
    {
        cin >> t, find(t) == i ? ans = min(ans, cnt) : fa[i] = t;
        cout<<"fa["<<i<<"]"<<fa[i]<<" ";
    }
    cout << ans;
    return 0;
}