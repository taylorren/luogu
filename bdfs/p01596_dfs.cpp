#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
vector<string> grid;

// DFS函数，用于标记连通的水区域
void dfs(int x, int y)
{
    // 如果坐标超出边界，或者不是水，或者已经访问过
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 'W')
    {
        return;
    }

    // 标记当前格子为已访问（用'.'表示）
    grid[x][y] = '.';

    // 递归访问8个方向
    for (int i = 0; i < 8; i++)
    {
        dfs(x + dx[i], y + dy[i]);
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
                // 开始一次DFS，标记所有连通的水格子
                dfs(i, j);
                // 找到一个新的水坑
                pond_count++;
            }
        }
    }

    // 输出结果
    cout << pond_count << endl;

    return 0;
}