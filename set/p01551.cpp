#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5'005;
int parents[MAXN];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
    }
}

int find(int u)
{
    if (u == parents[u])
    {
        return u;
    }
    return parents[u] = find(parents[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        parents[u] = v;
    }
}
int main()
{
    int n, m, p;

    cin>>n>>m>>p;
    init(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        merge(u, v);
    }

    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin>>u>>v;
        if (find(u) == find(v))
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }

    return 0;
}