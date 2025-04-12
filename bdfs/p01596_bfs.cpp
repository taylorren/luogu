#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
vector<string> grid;

// BFS函数，用于标记连通的水区域
void bfs(int x, int y)
{
    // 创建队列，存储要访问的坐标
    queue<pair<int, int>> q;
    q.push({x, y});

    // 标记起始点为已访问
    grid[x][y] = '.';

    while (!q.empty())
    {
        // 取出队列中的一个点
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        // 检查8个方向的相邻点
        for (int i = 0; i < 8; i++)
        {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];

            // 如果新坐标在网格内且是水
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] == 'W')
            {
                // 标记为已访问
                grid[new_x][new_y] = '.';
                // 将新坐标加入队列
                q.push({new_x, new_y});
            }
        }
    }
}

int main()
{
    // 读取输入
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int pond_count = 0;

    // 遍历整个网格
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 如果找到一个水格子
            if (grid[i][j] == 'W')
            {
                // 开始一次BFS，标记所有连通的水格子
                bfs(i, j);
                // 找到一个新的水坑
                pond_count++;
            }
        }
    }

    // 输出结果
    cout << pond_count << endl;

    return 0;
}