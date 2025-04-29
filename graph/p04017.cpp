#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 80112002;

struct Organism {
    int in_degree = 0;       // 入度
    int out_degree = 0;      // 出度
    vector<int> predators;   // 捕食者列表
    vector<int> prey;        // 被捕食者列表
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Organism> organisms(n+1);
    vector<int> dp(n+1, 0);
    queue<int> q;
    
    // 读取食物关系并构建图
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        organisms[a].predators.push_back(b);
        organisms[b].prey.push_back(a);
        organisms[a].out_degree++;
        organisms[b].in_degree++;
    }
    
    // 找到所有生产者（入度为0的节点）
    for (int i = 1; i <= n; ++i) {
        if (organisms[i].in_degree == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }
    
    // 拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : organisms[u].predators) {
            dp[v] = (dp[v] + dp[u]) % MOD;
            if (--organisms[v].in_degree == 0) {
                q.push(v);
            }
        }
    }
    
    // 找到所有顶级消费者（出度为0的节点）并累加结果
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        if (organisms[i].out_degree == 0) {
            result = (result + dp[i]) % MOD;
        }
    }
    
    cout << result << endl;
    return 0;
}