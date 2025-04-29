#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1500 + 1;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
int st_x, st_y;
int vis[MAXN][MAXN][3];
bool found, a[MAXN][MAXN];
char ch;

// DFS函数，x和y是当前的位置，lx和ly是相对于起点的位移
void dfs(int x, int y, int lx, int ly)
{
    if (found)
    {
        return;  // 如果已经找到循环路径，终止递归
    }
    // 如果当前位置已经被访问，并且位移与之前不同，则找到循环路径
    if (vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly))
    {
        found = 1;
        return;
    }
    // 标记当前位置已访问，并记录当前位移
    vis[x][y][1] = lx;
    vis[x][y][2] = ly;
    vis[x][y][0] = 1;
    // 尝试四个方向移动
    for (int i = 0; i < 4; ++i)
    {
        // 计算新的位置，考虑迷宫的周期性
        int xx = (x + dx[i] + n) % n;
        int yy = (y + dy[i] + m) % m;
        // 计算新的位移
        int lxx = lx + dx[i];
        int lyy = ly + dy[i];
        // 如果新位置不是墙壁，且满足未访问或位移不同，则继续DFS
        if (!a[xx][yy])
        {
            if (vis[xx][yy][1] != lxx || vis[xx][yy][2] != lyy ||
                !vis[xx][yy][0])
                dfs(xx, yy, lxx, lyy);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {  // 处理多组测试用例
        found = 0;
        memset(a, 0, sizeof(a));      // 初始化迷宫数组
        memset(vis, 0, sizeof(vis));  // 初始化访问数组
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> ch;
                if (ch == '#')
                    a[i][j] = 1;  // 标记墙壁
                if (ch == 'S')
                    st_x = i, st_y = j;  // 记录起点位置
            }
        dfs(st_x, st_y, st_x, st_y);  // 从起点开始DFS
        cout << (found ? "Yes" : "No") << endl;
    }
}
