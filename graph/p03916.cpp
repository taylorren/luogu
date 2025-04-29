#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
int ans[MAXN];

void dfs(int u, int max_v) {
    if (ans[u] >= max_v) return;
    ans[u] = max_v;
    for (int v : graph[u]) {
        dfs(v, max_v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // 反向建图
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u); // 反向存储边
    }
    
    // 从大到小遍历节点
    for (int i = n; i >= 1; --i) {
        if (!ans[i]) { // 如果还没处理过
            dfs(i, i); // 从当前节点开始DFS
        }
    }
    
    // 输出结果
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}