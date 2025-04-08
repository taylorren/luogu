#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> a(n + 1), b(n + 1);
    
    // 读取依赖关系
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        in_degree[y]++;
    }

    // 读取时间代价
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    int X;
    cin >> X;

    // 使用动态规划计算学习时间
    vector<int> dp(n + 1, numeric_limits<int>::max());
    queue<int> q;

    // 初始化直接学习时间
    for (int i = 1; i <= n; ++i) {
        dp[i] = b[i];  // 直接学习的时间
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // 拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // 更新后继节点的学习时间
        for (int v : graph[u]) {
            dp[v] = min(dp[v], dp[u] + a[v]); // 通过前置知识点学习
            in_degree[v]--;

            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 输出调试信息
    for (int i = 1; i <= n; ++i) {
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    // 输出结果
    cout << dp[X] << endl;

    return 0;
}