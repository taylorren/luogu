#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 100005;
int L, N, K;
int positions[MAXN];

// 检查是否能通过增设k个路标使得空旷指数不超过mid
bool check(int mid)
{
    int need = 0;  // 需要增设的路标数量

    for (int i = 1; i < N; i++)
    {
        int gap = positions[i] - positions[i - 1];  // 相邻路标之间的距离

        // 计算需要在这个间隔中增设多少个路标
        if (gap > mid)
        {
            need += (gap - 1) / mid;  // 向上取整的技巧：(a-1)/b + 1
        }
    }

    return need <= K;  // 如果需要增设的路标数量不超过K，则可行
}

int main()
{
    cin >> L >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> positions[i];
    }

    // 二分查找最小的空旷指数
    int left = 1, right = L;
    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (check(mid))
        {
            right = mid;  // 如果可行，尝试更小的空旷指数
        }
        else
        {
            left = mid + 1;  // 否则，尝试更大的空旷指数
        }
    }

    cout << left << endl;

    return 0;
}