#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const short WHITE=0;
const short BLUE=1;
const short RED=2;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
    }

    // 计算将每一行全部涂成特定颜色所需的操作次数
    vector<int> white_cost(N, 0);  // 将第i行涂成全白的成本
    vector<int> blue_cost(N, 0);   // 将第i行涂成全蓝的成本
    vector<int> red_cost(N, 0);    // 将第i行涂成全红的成本

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] != 'W')
                white_cost[i]++;
            if (grid[i][j] != 'B')
                blue_cost[i]++;
            if (grid[i][j] != 'R')
                red_cost[i]++;
        }
    }

    // 动态规划：dp[i][j]表示将前i+1行按特定颜色方案涂色的最小成本
    // j=WHITE: 前i+1行全是白色
    // j=BLUE: 前i+1行是白色+蓝色（上方白色，下方蓝色）
    // j=RED: 前i+1行是白色+蓝色+红色（上方白色，中间蓝色，下方红色）
    vector<vector<int>> dp(N, vector<int>(3, INT_MAX));

    // 初始化：第一行只能是白色
    dp[0][0] = white_cost[0];

    // 填充dp表
    for (int i = 1; i < N; i++)
    {
        // 情况1：前i行全是白色，当前行也涂成白色
        // 只有一种可能的前驱状态：dp[i-1][WHITE]
        dp[i][WHITE] = dp[i - 1][WHITE] + white_cost[i];

        // 情况2：前i行包含白色和蓝色
        // 2.1：前i-1行全是白色，当前行开始蓝色区域
        if (dp[i - 1][WHITE] != INT_MAX)
        {
            dp[i][BLUE] = dp[i - 1][WHITE] + blue_cost[i]; // 第一次赋值，无需使用min
        }
        // 2.2：前i-1行已经包含蓝色，当前行继续蓝色区域
        if (dp[i - 1][BLUE] != INT_MAX)
        {
            dp[i][BLUE] = min(dp[i][BLUE], dp[i - 1][BLUE] + blue_cost[i]); // 需要比较不同路径
        }

        // 情况3：前i行包含白色、蓝色和红色
        // 3.1：前i-1行是白色+蓝色，当前行开始红色区域
        if (dp[i - 1][BLUE] != INT_MAX)
        {
            dp[i][RED] = dp[i - 1][BLUE] + red_cost[i]; // 第一次赋值，无需使用min
        }
        // 3.2：前i-1行已经包含红色，当前行继续红色区域
        if (dp[i - 1][RED] != INT_MAX)
        {
            dp[i][RED] = min(dp[i][RED], dp[i - 1][RED] + red_cost[i]); // 需要比较不同路径
        }
    }

    // 最终结果是dp[N-1][RED]，表示将所有N行分成白+蓝+红三部分的最小成本
    // 这确保了最终方案符合题目要求：上方白色，中间蓝色，下方红色，且每种颜色至少有一行
    cout << dp[N - 1][RED] << endl;

    return 0;
}