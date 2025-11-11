#include <bits/stdc++.h>
using namespace std;

// 火把照明范围：十字形，曼哈顿距离 <= 2
void put_torch(vector<vector<bool>> &grid, int n, int m)
{
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        
        // 遍历以(x,y)为中心的区域
        for (int dx = -2; dx <= 2; dx++)
        {
            for (int dy = -2; dy <= 2; dy++)
            {
                // 曼哈顿距离 <= 2（十字形）
                if (abs(dx) + abs(dy) <= 2)
                {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                    {
                        grid[nx][ny] = true;
                    }
                }
            }
        }
    }
}

// 萤石照明范围：5x5正方形
void put_stone(vector<vector<bool>> &grid, int n, int k)
{
    int x, y;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        
        // 遍历5x5区域
        for (int dx = -2; dx <= 2; dx++)
        {
            for (int dy = -2; dy <= 2; dy++)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                {
                    grid[nx][ny] = true;
                }
            }
        }
    }
}

int main()
{
    int n, m, k;  // 方阵n，火把m，萤石k
    cin >> n >> m >> k;

    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));

    put_torch(grid, n, m);
    put_stone(grid, n, k);

    // 统计未被照亮的方块
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!grid[i][j])
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}