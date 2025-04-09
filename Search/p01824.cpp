#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 检查是否可以在最小距离为 d 的情况下放置 C 头牛
bool canPlaceCows(const vector<int>& stalls, int C, int d)
{
    int count = 1;                  // 放置第一头牛
    int last_position = stalls[0];  // 第一头牛的位置

    for (int i = 1; i < stalls.size(); ++i)
    {
        if (stalls[i] - last_position >= d)
        {
            count++;                    // 放置下一头牛
            last_position = stalls[i];  // 更新最后放置的位置
            if (count == C)
            {
                return true;  // 成功放置所有牛
            }
        }
    }
    return false;  // 无法放置所有牛
}

int main()
{
    int N, C;
    cin >> N >> C;

    vector<int> stalls(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> stalls[i];
    }

    // 排序隔间坐标
    sort(stalls.begin(), stalls.end());

    // 二分查找的范围
    int left = 1;  // 最小距离
    int max_distance = stalls[N - 1] - stalls[0];
    int right = min(max_distance, max_distance / (C - 1));  // 优化后的最大距离
    int result = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;  // 当前尝试的最小距离
        if (canPlaceCows(stalls, C, mid))
        {
            result = mid;    // 更新结果
            left = mid + 1;  // 尝试更大的最小距离
        }
        else
        {
            right = mid - 1;  // 尝试更小的最小距离
        }
    }

    cout << result << endl;
    return 0;
}