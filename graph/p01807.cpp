#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 建立邻接表，adj[u]存储所有从u出发的边(v, w)
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    // 初始化距离数组，dp[i]表示从1到i的最长路径长度
    vector<ll> dp(n + 1, -INF);
    dp[1] = 0;  // 起点到自身距离为0

    // 按照拓扑顺序遍历顶点（由于u < v，按1到n顺序即可）
    for (int u = 1; u <= n; ++u)
    {
        if (dp[u] == -INF)
            continue;  // 如果u不可达，则跳过
        for (auto &[v, w] : adj[u])
        {
            if (dp[v] < dp[u] + (ll)w)
            {
                dp[v] = dp[u] + (ll)w;
            }
        }
    }

    // 处理特殊情况
    if (dp[n] == -INF)
    {
        cout << -1;
    }
    else
    {
        cout << dp[n];
    }
}
