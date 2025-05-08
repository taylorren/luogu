#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 使用异或运算记录最终开着的灯
    // 如果一盏灯被按了奇数次，它就会在最终结果中
    int result = 0;

    // 处理n次操作
    for (int i = 0; i < n; i++)
    {
        double a;
        int t;
        cin >> a >> t;

        // 对于每次操作，计算被按的灯
        for (int j = 1; j <= t; j++)
        {
            int light_id = floor(j * a);
            
            // 使用异或运算记录灯的状态变化
            // 如果一盏灯在结果中出现奇数次，它就是开着的
            result ^= light_id;
        }
    }

    // 输出最终开着的灯的编号
    cout << result << endl;

    return 0;
}