#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

struct Node {
    int population;
    int left;
    int right;
    Node() : population(0), left(0), right(0) {}
};

Node tree[MAXN];
int n;
vector<vector<int>> adj;  // 邻接表表示树
vector<int> dist;         // 存储到当前医院的距离

// 使用BFS计算从hospital到所有其他节点的距离
int calcTotalDist(int hospital) {
    dist.assign(n + 1, -1);
    queue<int> q;
    q.push(hospital);
    dist[hospital] = 0;
    int total = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        total += dist[curr] * tree[curr].population;
        
        // 遍历所有相邻节点
        for (int next : adj[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    
    return total;
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        int w, u, v;
        cin >> w >> u >> v;
        tree[i].population = w;
        tree[i].left = u;
        tree[i].right = v;
        
        // 建立无向图
        if (u) {
            adj[i].push_back(u);
            adj[u].push_back(i);
        }
        if (v) {
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
    }
    
    int minDist = INT_MAX;
    for (int i = 1; i <= n; i++) {
        minDist = min(minDist, calcTotalDist(i));
    }
    
    cout << minDist << endl;
    
    return 0;
}