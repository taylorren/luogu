#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // 读取所有刺痛值
    vector<int> pain(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pain[i];
    }

    // 如果m为0，则最小和为0
    if (m == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    // 计算前m个刺痛值的和
    int current_sum = 0;
    for (int i = 0; i < m; i++)
    {
        current_sum += pain[i];
    }

    // 初始化最小和为前m个刺痛值的和
    int min_sum = current_sum;

    // 使用滑动窗口计算所有连续m个刺痛值的和
    for (int i = m; i < n; i++)
    {
        // 移除窗口最左边的元素，添加新的元素
        current_sum = current_sum - pain[i - m] + pain[i];

        // 更新最小和
        min_sum = min(min_sum, current_sum);
    }

    // 输出结果
    cout << min_sum << endl;

    return 0;
}