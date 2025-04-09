#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 100005;
int n, k;
int woods[MAXN];

// 检查是否能切割出k段长度为len的木材
bool check(int len)
{
    if (len == 0)
        return true;  // 长度为0时总是可以切割出任意段

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += woods[i] / len;  // 每根木材能切割出的段数
    }

    return count >= k;  // 如果总段数大于等于k，则可以切割
}

int main()
{
    cin >> n >> k;

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> woods[i];
        maxLen = max(maxLen, woods[i]);  // 找出最长的木材
    }

    // 二分查找最大长度
    int left = 0, right = maxLen;
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;  // 向上取整

        if (check(mid))
        {
            left = mid;  // 如果能切割，尝试更大的长度
        }
        else
        {
            right = mid - 1;  // 否则，尝试更小的长度
        }
    }

    cout << left << endl;

    return 0;
}