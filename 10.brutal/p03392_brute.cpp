#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
    }

    // 预计算：将每一行涂成特定颜色的成本
    vector<int> white_cost(N);
    vector<int> blue_cost(N);
    vector<int> red_cost(N);

    for (int i = 0; i < N; i++)
    {
        white_cost[i] = 0;
        blue_cost[i] = 0;
        red_cost[i] = 0;

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

    int min_cost = INT_MAX;

    // 暴力枚举所有可能的分界线
    // i: 白色区域的最后一行（0-indexed）
    // j: 蓝色区域的最后一行（0-indexed）
    for (int i = 0; i < N - 2; i++)  // 白色至少1行，蓝色和红色各至少1行
    {
        for (int j = i + 1; j < N - 1; j++)  // 蓝色至少1行，红色至少1行
        {
            int cost = 0;

            // 计算白色区域成本：[0, i]
            for (int row = 0; row <= i; row++)
            {
                cost += white_cost[row];
            }

            // 计算蓝色区域成本：[i+1, j]
            for (int row = i + 1; row <= j; row++)
            {
                cost += blue_cost[row];
            }

            // 计算红色区域成本：[j+1, N-1]
            for (int row = j + 1; row < N; row++)
            {
                cost += red_cost[row];
            }

            min_cost = min(min_cost, cost);
        }
    }

    cout << min_cost << endl;

    return 0;
}
