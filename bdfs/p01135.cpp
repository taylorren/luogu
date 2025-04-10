#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 205;
int n, a, b;     // n层楼，从a层到b层
int k[MAXN];     // 每层楼的数字
int dist[MAXN];  // 到达每层的最少按键次数

void bfs()
{
    memset(dist, -1, sizeof(dist));  // 初始化为-1表示未访问
    queue<int> q;

    // 从起点开始
    q.push(a);
    dist[a] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 尝试向上
        int up = cur + k[cur];
        if (up <= n && dist[up] == -1)
        {
            dist[up] = dist[cur] + 1;
            q.push(up);
        }

        // 尝试向下
        int down = cur - k[cur];
        if (down >= 1 && dist[down] == -1)
        {
            dist[down] = dist[cur] + 1;
            q.push(down);
        }
    }
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }

    bfs();
    cout << dist[b] << endl;

    return 0;
}