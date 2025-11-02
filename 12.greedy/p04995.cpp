#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    // 对石头高度进行排序
    sort(heights.begin(), heights.end());

    // 重新排列石头顺序，使相邻石头高度差最大
    vector<int> order;
    int left = 0, right = n - 1;

    // 从地面开始，先跳到最高的石头
    long long energy = heights[right] * heights[right];  // 从地面跳到最高石头
    order.push_back(heights[right]);
    right--;

    // 交替跳到最低和最高的石头
    while (left <= right)
    {
        // 如果还有石头，跳到最低的
        if (left <= right)
        {
            energy +=
                (order.back() - heights[left]) * (order.back() - heights[left]);
            order.push_back(heights[left]);
            left++;
        }

        // 如果还有石头，跳到最高的
        if (left <= right)
        {
            energy += (order.back() - heights[right]) *
                      (order.back() - heights[right]);
            order.push_back(heights[right]);
            right--;
        }
    }

    cout << energy << endl;

    return 0;
}