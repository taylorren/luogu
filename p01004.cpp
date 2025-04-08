#include "iostream"
using namespace std;
#define N 12
int value[N][N];
int dp[N][N][N][N];
int n, a, b, c;
int main()
{
    cin >> n; // 确定nXn
    // 输入与赋值操作,将c赋值给value
    while(1)
    {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)
            break;
        value[a][b] = c;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                for(int t = 1; t <= n; t++)
                {
                    dp[i][j][k][t] =
                        max(max(dp[i - 1][j][k - 1][t], dp[i][j - 1][k][t - 1]),
                            max(dp[i][j - 1][k - 1][t],
                                dp[i - 1][j][k][t - 1])) +
                        value[i][j];
                    if(i != k && j != t)
                        dp[i][j][k][t] += value[k][t];
                }
            }
        }
    }
    cout << dp[n][n][n][n];
    return 0;
}
//这道题和OJ.02.06.8786是一样的