#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // 记录已经找到的满足条件的数，避免重复计数
    vector<bool> found(20001, false);  // 假设数的范围不超过20000
    int count = 0;

    // 枚举所有可能的数对
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = nums[i] + nums[j];

            // 检查和是否在集合中，且不是当前的两个数
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j && nums[k] == sum && !found[sum])
                {
                    found[sum] = true;
                    count++;
                    break;  // 找到一个就可以了，避免重复计数
                }
            }
        }
    }

    // 输出满足条件的数的个数
    cout << count << endl;

    return 0;
}