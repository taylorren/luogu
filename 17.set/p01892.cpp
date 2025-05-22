#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005;
int parent[MAXN];
int enemy[MAXN];

// 查找根节点并进行路径压缩
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 合并两个集合
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        enemy[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        char opt;
        int p, q;
        cin >> opt >> p >> q;

        if (opt == 'F') {
            // 朋友关系
            unite(p, q);
        } else if (opt == 'E') {
            // 敌人关系
            if (enemy[p] == 0) enemy[p] = q;
            else unite(enemy[p], q);

            if (enemy[q] == 0) enemy[q] = p;
            else unite(enemy[q], p);
        }
    }

    // 统计团体数
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (find(i) == i) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}