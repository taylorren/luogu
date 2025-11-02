#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int parents[MAXN];

// 初始化并查集
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
    }
}

// 查找根节点（带路径压缩）
int find(int u)
{
    if (u == parents[u])
    {
        return u;
    }
    int root = find(parents[u]);
    parents[u] = root;
    return root;
}

// 合并两个集合
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        parents[u] = v;
    }
}

// 计算连通分量的数量
int countSets(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parents[i] == i)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n, m;
    
    while (cin >> n && n != 0)
    {
        cin >> m;
        init(n);
        
        // 读入道路信息并合并集合
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        
        // 需要的最少道路数 = 连通分量数 - 1
        cout << countSets(n) - 1 << endl;
    }
    
    return 0;
}