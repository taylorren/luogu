#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int w, n;
    cin >> w >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    // 按价格排序
    sort(prices.begin(), prices.end());

    int groups = 0;     // 分组数
    int left = 0;       // 指向最便宜的纪念品
    int right = n - 1;  // 指向最贵的纪念品

    while (left <= right)
    {
        // 如果只剩一件纪念品，或者最便宜和最贵的纪念品不能配对
        if (left == right || prices[left] + prices[right] > w)
        {
            // 最贵的纪念品单独一组
            groups++;
            right--;
        }
        else
        {
            // 最便宜和最贵的纪念品配对一组
            groups++;
            left++;
            right--;
        }
    }

    cout << groups << endl;

    return 0;
}