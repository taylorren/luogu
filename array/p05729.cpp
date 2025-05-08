#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, x, h, q;
    cin >> w >> x >> h;
    cin >> q;

    // 创建一个三维数组来标记每个小方块是否被移除
    // 初始时，所有小方块都未被移除（false）
    vector<vector<vector<bool>>> removed(
        w + 1, vector<vector<bool>>(x + 1, vector<bool>(h + 1, false)));

    // 处理每次切割
    for (int i = 0; i < q; i++)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        // 标记被切割区域内的所有小方块为已移除
        for (int a = x1; a <= x2; a++)
        {
            for (int b = y1; b <= y2; b++)
            {
                for (int c = z1; c <= z2; c++)
                {
                    removed[a][b][c] = true;
                }
            }
        }
    }

    // 统计剩余的小方块数量
    int remaining = 0;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= h; k++)
            {
                if (!removed[i][j][k])
                {
                    remaining++;
                }
            }
        }
    }

    cout << remaining << endl;

    return 0;
}