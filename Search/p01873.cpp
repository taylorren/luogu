#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 计算在高度 H 时可以获得的木材总长度
long long getWood(const vector<int>& trees, int H)
{
    long long total = 0;
    for (int height : trees)
    {
        if (height > H)
        {
            total += height - H;
        }
    }
    return total;
}

int main()
{
    int N;        // 树的数量
    long long M;  // 需要的木材总长度
    cin >> N >> M;

    vector<int> trees(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> trees[i];
    }

    // 二分查找的范围
    int left = 0, right = *max_element(trees.begin(), trees.end());
    int result = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;   // 当前锯片高度
        long long wood = getWood(trees, mid);  // 计算木材总长度

        if (wood >= M)
        {
            // 如果木材总长度满足要求，尝试更高的锯片高度
            result = mid;
            left = mid + 1;
        }
        else
        {
            // 如果木材总长度不足，降低锯片高度
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}