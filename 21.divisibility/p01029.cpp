#include <bits/stdc++.h>
using namespace std;

// 计算最大公约数
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int x0, y0;
    cin >> x0 >> y0;

    // 检查 y0 是否能被 x0 整除
    if (y0 % x0 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    // 计算 m = y0/x0
    int m = y0 / x0;

    // 统计满足条件的对数
    int count = 0;

    // 枚举 m 的所有因子
    for (int i = 1; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            // i 和 m/i 是 m 的一对因子
            int j = m / i;

            // 检查 i 和 j 是否互质
            if (gcd(i, j) == 1)
            {
                // 如果 i 和 j 相等，只有一对 (P,Q)
                // 否则有两对：(x0*i, x0*j) 和 (x0*j, x0*i)
                count += (i == j) ? 1 : 2;
            }
        }
    }

    cout << count << endl;
    return 0;
}