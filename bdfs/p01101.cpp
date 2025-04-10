#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n;
char matrix[MAXN][MAXN];
bool mark[MAXN][MAXN];
string target = "yizhong";

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// DFS搜索
bool dfs(int x, int y, int dir, int pos)
{
    if (pos == target.length())
    {
        return true;
    }

    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        return false;
    }
    if (matrix[x][y] != target[pos])
    {
        return false;
    }
    // 继续在同一方向搜索下一个字符
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (dfs(nx, ny, dir, pos + 1))
    {
        mark[x][y] = true;  // 回溯时标记
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            mark[i][j] = false;
        }
    }

    // 从每个'y'开始，尝试八个方向
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 'y')
            {
                for (int dir = 0; dir < 8; dir++)
                {
                    dfs(i, j, dir, 0);
                }
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (mark[i][j] ? matrix[i][j] : '*');
        }
        cout << endl;
    }
    return 0;
}