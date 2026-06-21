#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 1000;

int countWays1D(const int prices[], int N, int M)
{
    int dp[MAX_M + 1] = {0};
    dp[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        int price = prices[i];
        for (int j = M; j >= price; j--)
        {
            dp[j] += dp[j - price];
        }
    }

    return dp[M];
}

int countWays2D(const int prices[], int N, int M)
{
    // dp[i][sum]: number of ways to make exact amount 'sum' using the first i items.
    int dp[MAX_N + 1][MAX_M + 1] = {0};
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        int price = prices[i];
        for (int sum = 0; sum <= M; sum++)
        {
            // Case 1: do not take item i.
            dp[i][sum] = dp[i - 1][sum];
            if (sum >= price)
            {
                // Case 2: take item i, so previous sum is (sum - price).
                dp[i][sum] += dp[i - 1][sum - price];
            }
        }
    }

    return dp[N][M];
}

int main()
{
    int N, M;
    cin >> N >> M;

    int prices[MAX_N + 1] = {0};
    for (int i = 1; i <= N; i++)
    {
        cin >> prices[i];
    }

    cout << countWays2D(prices, N, M) << endl;

    return 0;
}