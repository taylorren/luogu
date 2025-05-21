#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int MAXV = 1000005;

int n;
int a[MAXN];
int cnt[MAXV];  // cnt[i]表示能被i整除的学生数量
int ans[MAXN];  // ans[k]表示选k个学生时的最大公约数

int main()
{
    cin >> n;

    int maxVal = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    // 统计每个因子能被多少个学生的能力值整除
    for (int i = 1; i <= n; i++)
    {
        // 枚举a[i]的所有因子
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                cnt[j]++;
                if (j * j != a[i])
                {
                    cnt[a[i] / j]++;
                }
            }
        }
    }

    // 从大到小枚举所有可能的因子
    for (int i = maxVal; i >= 1; i--)
    {
        // 如果有cnt[i]个学生的能力值能被i整除
        // 那么对于k=1,2,...,cnt[i]，i都是一个可能的答案
        for (int k = 1; k <= cnt[i]; k++)
        {
            if (ans[k] == 0)
            {  // 如果ans[k]还没有被赋值
                ans[k] = i;
            }
        }
    }

    // 输出结果
    for (int k = 1; k <= n; k++)
    {
        cout << ans[k] << endl;
    }

    return 0;
}