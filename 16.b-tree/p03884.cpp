#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 110;
vector<int> tree[MAXN];
int depth[MAXN];   // 每个节点的深度
int parent[MAXN];  // 每个节点的父节点
int n;

// BFS求深度和宽度
int getDepthAndWidth(int root, int& maxWidth)
{
    queue<int> q;
    q.push(root);
    depth[root] = 1;
    int maxDepth = 1;
    vector<int> levelCount(MAXN, 0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int d = depth[u];
        levelCount[d]++;
        maxDepth = max(maxDepth, d);

        for (int v : tree[u])
        {
            if (depth[v] == 0)
            {
                depth[v] = d + 1;
                // 移除重复计算的parent赋值
                q.push(v);
            }
        }
    }

    // 修正：从1开始计数，找出最大宽度
    maxWidth = 0;
    for (int i = 1; i <= maxDepth; i++)
    {
        maxWidth = max(maxWidth, levelCount[i]);
    }

    return maxDepth;
}

// 求LCA
int getLCA(int x, int y)
{
    while (depth[x] > depth[y])
        x = parent[x];
    while (depth[y] > depth[x])
        y = parent[y];
    while (x != y)
    {
        x = parent[x];
        y = parent[y];
    }
    return x;
}

// 求距离
int getDistance(int x, int y)
{
    int lca = getLCA(x, y);

    // 计算x和y到LCA的距离
    int dx = depth[x] - depth[lca];
    int dy = depth[y] - depth[lca];

    // 修正：根据题目定义，距离 = 向根的边数*2 + 向叶的边数
    // 从x到y的路径中，向根的边数是dx，向叶的边数是dy
    return dx * 2 + dy;
}

int main()
{
    cin >> n;

    // 初始化
    for (int i = 0; i <= n; i++)
    {
        tree[i].clear();
    }
    fill(depth, depth + MAXN, 0);
    fill(parent, parent + MAXN, 0);

    // 按题意构建有向树，同时记录父节点关系
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);  // u是v的父节点
        parent[v] = u;         // 直接记录父节点
    }

    int x, y;
    cin >> x >> y;

    int maxWidth = 0;
    int maxDepth = getDepthAndWidth(1, maxWidth);

    cout << maxDepth << endl;
    cout << maxWidth << endl;
    cout << getDistance(x, y) << endl;

    return 0;
}