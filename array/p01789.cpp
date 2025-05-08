#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    // 创建一个n×n的二维数组，初始化为0（未照亮）
    vector<vector<bool>> illuminated(n + 1, vector<bool>(n + 1, false));

    // 处理火把
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        // 标记火把位置
        illuminated[x][y] = true;

        // 标记火把照亮的区域
        // 十字形
        if (x - 2 >= 1)
            illuminated[x - 2][y] = true;
        if (x - 1 >= 1)
        {
            illuminated[x - 1][y] = true;
            if (y - 1 >= 1)
                illuminated[x - 1][y - 1] = true;
            if (y + 1 <= n)
                illuminated[x - 1][y + 1] = true;
        }
        if (x + 1 <= n)
        {
            illuminated[x + 1][y] = true;
            if (y - 1 >= 1)
                illuminated[x + 1][y - 1] = true;
            if (y + 1 <= n)
                illuminated[x + 1][y + 1] = true;
        }
        if (x + 2 <= n)
            illuminated[x + 2][y] = true;

        if (y - 2 >= 1)
            illuminated[x][y - 2] = true;
        if (y - 1 >= 1)
            illuminated[x][y - 1] = true;
        if (y + 1 <= n)
            illuminated[x][y + 1] = true;
        if (y + 2 <= n)
            illuminated[x][y + 2] = true;
    }

    // 处理萤石
    for (int i = 0; i < k; i++)
    {
        int o, p;
        cin >> o >> p;

        // 标记萤石位置
        illuminated[o][p] = true;

        // 标记萤石照亮的区域（5×5的正方形）
        for (int dx = -2; dx <= 2; dx++)
        {
            for (int dy = -2; dy <= 2; dy++)
            {
                int nx = o + dx;
                int ny = p + dy;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                {
                    illuminated[nx][ny] = true;
                }
            }
        }
    }

    // 统计未被照亮的位置数量
    int monster_count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!illuminated[i][j])
            {
                monster_count++;
            }
        }
    }

    cout << monster_count << endl;

    return 0;
}