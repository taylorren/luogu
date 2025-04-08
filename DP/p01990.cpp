#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    const int mod = 10000; // 取模值

    // 使用二维DP数组
    // dp[i][j] 表示覆盖到第i列时的状态j的方案数
    vector<vector<int>> dp(N + 1, vector<int>(4, 0));

    // 初始化基础情况
    dp[0][3] = 1; // 初始状态为全空，只有一种方案

    // 填充dp表
    for (int i = 1; i <= N; i++) {
        // 根据提供的状态转移方程
        dp[i][0] = dp[i - 1][3];
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][3] = (((dp[i - 1][0] + dp[i - 1][1]) % mod + dp[i - 1][2]) % mod + dp[i - 1][3]) % mod;
    }

    // 结果是dp[N][3]
    cout << dp[N][3] << endl;

    return 0;
}