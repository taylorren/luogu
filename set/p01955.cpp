#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// 不再需要MAXN
map<int, int> parent;

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        parent[fx] = fy;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> eq, neq;
        set<int> vars;
        for (int i = 0; i < n; ++i)
        {
            int a, b, e;
            cin >> a >> b >> e;
            vars.insert(a);
            vars.insert(b);
            if (e == 1)
                eq.push_back(make_pair(a, b));
            else
                neq.push_back(make_pair(a, b));
        }
        // 初始化parent
        parent.clear();
        for (int v : vars)
            parent[v] = v;
        for (size_t i = 0; i < eq.size(); ++i)
            unite(eq[i].first, eq[i].second);
        bool ok = true;
        for (size_t i = 0; i < neq.size(); ++i)
        {
            if (find(neq[i].first) == find(neq[i].second))
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}