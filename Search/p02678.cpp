#include <bits/stdc++.h>
using namespace std;

int l, n, m, positions[50005];  // 修改数组大小为更合理的值

// 检查是否可以通过移除最多 m 个石头来确保最小跳跃距离不小于 mid
bool valid(int mid)
{
    int prev = 0;     // 上一个保留的石头位置
    int removed = 0;  // 需要移除的石头数量

    for (int i = 1; i <= n; i++)
    {
        // 如果当前石头与前一个石头的距离小于 mid，需要移除当前石头
        if (positions[i] - prev < mid)
        {
            removed++;
        }
        else
        {
            prev = positions[i];
        }
    }

    // 检查最后一段距离
    if (l - prev < mid)
    {
        removed++;
    }

    return removed <= m;
}

int main()
{
    cin >> l >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> positions[i];
    }

    int left = 1;   // 最小可能的跳跃距离
    int right = l;  // 最大可能的跳跃距离
    int ans = 0;

    // 二分查找最大的可能跳跃距离
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (valid(mid))
        {
            ans = mid;
            left = mid + 1;  // 尝试更大的距离
        }
        else
        {
            right = mid - 1;  // 尝试更小的距离
        }
    }

    cout << ans << endl;
    return 0;
}