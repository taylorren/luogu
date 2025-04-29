#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

// 站点结构体
struct Station {
    vector<int> outEdges;  // 出边列表
    int inDegree = 0;      // 入度
    int level = 1;         // 级别，初始为1
};

int n, m;
Station stations[MAXN];
bool edge_exists[MAXN][MAXN]; // 记录边是否已存在

int main() {
    cin >> n >> m;
    
    // 初始化
    memset(edge_exists, 0, sizeof(edge_exists));
    
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        
        vector<int> stops(s);
        for (int j = 0; j < s; j++) {
            cin >> stops[j];
        }
        
        // 标记所有停靠站点
        vector<bool> is_stop(n + 1, false);
        for (int stop : stops) {
            is_stop[stop] = true;
        }
        
        // 找出这趟车次的起点和终点
        int start_station = stops[0];
        int end_station = stops[s-1];
        
        // 对于起点到终点之间的每个未停靠站点
        for (int k = start_station + 1; k < end_station; k++) {
            if (!is_stop[k]) {
                // 只需要建立未停靠站点到停靠站点的边
                // 并且避免重复添加边
                for (int stop : stops) {
                    if (!edge_exists[k][stop]) {
                        stations[k].outEdges.push_back(stop);
                        stations[stop].inDegree++;
                        edge_exists[k][stop] = true;
                    }
                }
            }
        }
    }
    
    // 拓扑排序找最长路径
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (stations[i].inDegree == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int next : stations[curr].outEdges) {
            stations[next].inDegree--;
            // 更新级别
            stations[next].level = max(stations[next].level, stations[curr].level + 1);
            if (stations[next].inDegree == 0) {
                q.push(next);
            }
        }
    }
    
    // 找出最大级别
    int max_level = 0;
    for (int i = 1; i <= n; i++) {
        max_level = max(max_level, stations[i].level);
    }
    
    cout << max_level << endl;
    
    return 0;
}