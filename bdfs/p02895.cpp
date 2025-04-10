#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 305;
const int INF = 0x3f3f3f3f;
int m;
int destroyed[MAXN][MAXN];  // 记录每个格子被摧毁的时间，INF表示永不摧毁
int dist[MAXN][MAXN];      // 到达每个格子的最短时间
int dx[] = {0, 0, 1, -1};  // 四个方向的移动
int dy[] = {1, -1, 0, 0};

struct Point
{
    int x, y, t;
    Point(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

bool valid(int x, int y)
{
    return x >= 0 && y >= 0;
}

void bfs()
{
    memset(dist, -1, sizeof(dist));
    queue<Point> q;

    // 从原点开始
    q.push(Point(0, 0, 0));
    dist[0][0] = 0;

    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();

        // 如果当前点永不被摧毁，找到安全点
        if (destroyed[cur.x][cur.y] == INF)
        {
            cout << cur.t << endl;
            return;
        }

        // 尝试四个方向
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nt = cur.t + 1;

            if (valid(nx, ny) && dist[nx][ny] == -1 && nt < destroyed[nx][ny])
            {
                dist[nx][ny] = nt;
                q.push(Point(nx, ny, nt));
            }
        }
    }

    cout << -1 << endl;  // 无法到达安全点
}

int main()
{
    // 初始化所有格子为永不摧毁
    memset(destroyed, INF, sizeof(destroyed));

    cin >> m;
    // 读入每颗流星的信息
    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;

        // 更新流星落点本身
        if (valid(x, y))
        {
            destroyed[x][y] = min(destroyed[x][y], t);
        }

        // 更新四个相邻格子
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (valid(nx, ny))
            {
                destroyed[nx][ny] = min(destroyed[nx][ny], t);
            }
        }
    }

    bfs();
    return 0;
}