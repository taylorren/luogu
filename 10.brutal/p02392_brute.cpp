#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 25;
int s[5];            // 每科题目数量
int times[5][MAXN];  // 每科每道题的时间
int total = 0;       // 总时间

// 暴力枚举：使用位运算枚举所有可能的分配方案
int solve_subject_brute(int subject_id)
{
    int n = s[subject_id];
    int min_time = 1e9;

    // 枚举所有可能的分配方案，用位掩码表示
    // 0表示分配给左大脑，1表示分配给右大脑
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int left_time = 0, right_time = 0;

        // 根据位掩码计算左右大脑的时间
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                // 第i题分配给右大脑
                right_time += times[subject_id][i + 1];
            }
            else
            {
                // 第i题分配给左大脑
                left_time += times[subject_id][i + 1];
            }
        }

        // 更新最小完成时间
        min_time = min(min_time, max(left_time, right_time));
    }

    return min_time;
}

int main()
{
    // 读入每科题目数量
    for (int i = 1; i <= 4; i++)
    {
        cin >> s[i];
    }

    // 读入每科每道题的时间
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= s[i]; j++)
        {
            cin >> times[i][j];
        }
    }

    // 计算每科所需时间并累加
    for (int i = 1; i <= 4; i++)
    {
        total += solve_subject_brute(i);
    }

    cout << total << endl;
    return 0;
}