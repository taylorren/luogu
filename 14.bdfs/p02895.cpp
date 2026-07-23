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

int bfs()
{
    memset(dist, -1, sizeof(dist));
    queue<Point> q;

    q.push(Point(0, 0, 0));
    dist[0][0] = 0;

    int ans = -1;
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();

        if (destroyed[cur.x][cur.y] == INF)
        {
            ans = cur.t;
            break;
        }

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

    return ans;
}

void update_destroyed(int x, int y, int t)
{
    if (valid(x, y))
        destroyed[x][y] = min(destroyed[x][y], t);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny))
            destroyed[nx][ny] = min(destroyed[nx][ny], t);
    }
}

int main()
{
    // 初始化所有格子为永不摧毁
    memset(destroyed, INF, sizeof(destroyed));

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        update_destroyed(x, y, t);
    }

    int ans = bfs();
    cout << ans << endl;
    return 0;
}