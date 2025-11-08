#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, x, h;
    int q;

    cin >> w >> x >> h >> q;

    bool cube[21][21][21];
    fill(&cube[0][0][0], &cube[0][0][0] + 21*21*21, true);  // 初始化为true

    while (q--)
    {
        int x1, y1, z1;
        int x2, y2, z2;

        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                for (int k = z1; k <= z2; k++)
                {
                    cube[i][j][k] = false;  // 移除方块
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= h; k++)
            {
                if (cube[i][j][k])  // 统计剩余的方块
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}