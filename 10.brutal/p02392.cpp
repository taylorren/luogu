#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 25;
int s[5];            // 每科题目数量
int times[5][MAXN];  // 每科每道题的时间
int total = 0;       // 总时间

// DFS函数：当前处理到第idx题，左右大脑已用时间
void dfs(int subject_id, int idx, int left, int right, int& min_time)
{
    if (idx > s[subject_id])
    {
        min_time = min(min_time, max(left, right));
        return;
    }

    // 分配给左边
    dfs(subject_id, idx + 1, left + times[subject_id][idx], right, min_time);
    // 分配给右边
    dfs(subject_id, idx + 1, left, right + times[subject_id][idx], min_time);
}

// 计算单科最短时间
int solve_subject(int subject_id)
{
    int min_time = 1e9;  // 记录最小时间
    dfs(subject_id, 1, 0, 0, min_time);
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
        total += solve_subject(i);
    }

    cout << total << endl;
    return 0;
}