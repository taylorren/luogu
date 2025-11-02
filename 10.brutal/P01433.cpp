#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;
int n;
double x[MAXN], y[MAXN];
double dp[1 << MAXN]
         [MAXN];  // dp[state][last]表示访问state中的点，以last为终点的最短距离
double dist[MAXN][MAXN];  // 存储点之间的距离

double getDistance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }

    // 预处理所有点对之间的距离
    for (int i = 0; i <= n; i++)
    {
        double x1 = (i == 0) ? 0 : x[i];
        double y1 = (i == 0) ? 0 : y[i];
        for (int j = 0; j <= n; j++)
        {
            double x2 = (j == 0) ? 0 : x[j];
            double y2 = (j == 0) ? 0 : y[j];
            dist[i][j] = getDistance(x1, y1, x2, y2);
        }
    }

    // 初始化dp数组
    for (int s = 0; s < (1 << n); s++)
    {
        for (int i = 0; i <= n; i++)
        {
            dp[s][i] = 1e9;
        }
    }
    dp[0][0] = 0;  // 起点在(0,0)

    // 枚举所有状态
    for (int s = 0; s < (1 << n); s++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i > 0 && !(s & (1 << (i - 1))))
            {
                continue;  // i不在当前状态中
            }
            for (int j = 1; j <= n; j++)
            {
                if (s & (1 << (j - 1)))
                {
                    continue;  // j已经在当前状态中
                }
                int new_s = s | (1 << (j - 1));
                dp[new_s][j] = min(dp[new_s][j], dp[s][i] + dist[i][j]);
            }
        }
    }

    // 找出最终答案
    double ans = 1e9;
    int final_state = (1 << n) - 1;  // 所有点都要访问
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[final_state][i]);
    }

    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}