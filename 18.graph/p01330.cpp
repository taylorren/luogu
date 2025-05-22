#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

int n, m;
vector<int> graph[MAXN];
int color[MAXN]; // 0: 未染色, 1: 颜色1, 2: 颜色2

// 使用DFS进行二分图染色
bool dfs(int u, int c, int& count1, int& count2) {
    color[u] = c;
    if (c == 1) count1++;
    else count2++;
    
    for (int v : graph[u]) {
        if (color[v] == 0) {
            // 相邻节点染成相反的颜色
            if (!dfs(v, 3 - c, count1, count2)) return false;
        } else if (color[v] == c) {
            // 如果相邻节点颜色相同，则不是二分图
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    
    // 构建无向图
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 检查图是否为二分图
    bool isBipartite = true;
    int totalMinCover = 0;
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            int count1 = 0, count2 = 0;
            if (!dfs(i, 1, count1, count2)) {
                isBipartite = false;
                break;
            }
            totalMinCover += min(count1, count2);
        }
    }
    
    if (!isBipartite) {
        cout << "Impossible" << endl;
    } else {
        cout << totalMinCover << endl;
    }
    
    return 0;
}