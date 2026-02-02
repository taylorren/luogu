#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 15;
int n;
int s[MAXN], b[MAXN];  // 每种食材的酸度和苦度

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> b[i];
    }

    int min_diff = 1e9;

    // 暴力枚举所有可能的食材组合
    // 从1到(1<<n)-1，排除空集合（至少选择一种食材）
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int sour = 1;    // 酸度初始为1（乘法单位元）
        int bitter = 0;  // 苦度初始为0（加法单位元）

        // 根据位掩码计算当前组合的酸度和苦度
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                // 选择第i种食材
                sour *= s[i];
                bitter += b[i];
            }
        }

        // 更新最小差值
        min_diff = min(min_diff, abs(sour - bitter));
    }

    cout << min_diff << endl;
    return 0;
}