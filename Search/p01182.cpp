#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 100005;
int N, M;
int A[MAXN];

// 检查是否能将数组分成不超过M段，使得每段和不超过mid
bool check(int mid)
{
    int cnt = 1;  // 当前段数
    int sum = 0;  // 当前段的和

    for (int i = 0; i < N; i++)
    {
        // 如果单个元素就超过mid，无法分段
        if (A[i] > mid)
            return false;

        // 如果加上当前元素超过mid，则需要开始新的一段
        if (sum + A[i] > mid)
        {
            cnt++;
            sum = A[i];
        }
        else
        {
            sum += A[i];
        }
    }

    return cnt <= M;  // 如果段数不超过M，则可行
}

int main()
{
    cin >> N >> M;

    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
        maxVal = max(maxVal, A[i]);
    }

    // 二分查找最小的最大值
    int left = maxVal;  // 最小值不会小于数组中的最大值
    int right = sum;    // 最大值不会大于数组总和

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (check(mid))
        {
            right = mid;  // 如果可行，尝试更小的值
        }
        else
        {
            left = mid + 1;  // 否则，尝试更大的值
        }
    }

    cout << left << endl;

    return 0;
}