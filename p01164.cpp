#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> prices(N);
    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    // dp[i] 表示总价格恰好为i的方案数
    vector<int> dp(M + 1, 0);
    dp[0] = 1;  // 不选任何菜，价格为0的方案数为1

    // 对每种菜品进行动态规划
    for (int i = 0; i < N; i++)
    {
        // 从大到小遍历，避免重复计算
        for (int j = M; j >= prices[i]; j--)
        {
            dp[j] += dp[j - prices[i]];
        }
    }

    cout << dp[M] << endl;

    return 0;
}