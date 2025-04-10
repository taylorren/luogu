#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6;
int n, m, t;               // 迷宫大小和障碍数量
int sx, sy, fx, fy;        // 起点和终点坐标
bool maze[MAXN][MAXN];     // 迷宫地图，true表示障碍
bool visited[MAXN][MAXN];  // 访问标记
int ans = 0;               // 方案数

// 四个方向：上下左右
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    // 到达终点
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }

    // 尝试四个方向
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 检查新位置是否合法
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !maze[nx][ny] &&
            !visited[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(nx, ny);
            visited[nx][ny] = false;  // 回溯
        }
    }
}

int main()
{
    // 输入迷宫大小和障碍数量
    cin >> n >> m >> t;

    // 输入起点和终点
    cin >> sx >> sy >> fx >> fy;

    // 输入障碍位置
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        maze[x][y] = true;
    }

    // 标记起点为已访问
    visited[sx][sy] = true;

    // 开始搜索
    dfs(sx, sy);

    // 输出结果
    cout << ans << endl;

    return 0;
}