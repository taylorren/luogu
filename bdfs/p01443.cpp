#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 405;
int n, m, x, y;
int dist[MAXN][MAXN];  // 存储到达每个点的最少步数
// 马可以走的8个方向
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// 检查点是否在棋盘内
bool valid(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs()
{
    memset(dist, -1, sizeof(dist));  // 初始化所有点为-1
    queue<Point> q;

    // 起点入队
    q.push(Point(x, y));
    dist[x][y] = 0;

    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();

        // 尝试8个方向
        for (int i = 0; i < 8; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // 如果新位置有效且未访问过
            if (valid(nx, ny) && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push(Point(nx, ny));
            }
        }
    }
}

int main()
{
    cin >> n >> m >> x >> y;

    bfs();

    // 输出结果
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << "    ";
        }
        cout << endl;
    }

    return 0;
}