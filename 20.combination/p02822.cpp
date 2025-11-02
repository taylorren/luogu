#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
int C[MAXN][MAXN];  // 存储组合数C(i,j)
int row_count[MAXN]; // 存储每行中能被k整除的元素数量

// 预处理组合数
void init_combinations(int k)
{
    // 初始化边界条件
    for (int i = 0; i < MAXN; i++)
    {
        C[i][0] = 1;  // C(i,0) = 1
    }

    // 使用递推公式计算组合数
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
        }
    }

    // 预计算每行中能被k整除的元素数量
    for (int i = 0; i < MAXN; i++)
    {
        int count = 0;
        for (int j = 0; j <= i; j++)
        {
            if (C[i][j] == 0)
            {
                count++;
            }
        }
        row_count[i] = count;
    }
}

int main()
{
    int t, k;
    cin >> t >> k;

    // 预处理所有可能的组合数对k的余数
    init_combinations(k);

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int count = 0;
        
        // 使用预计算的行数据加速计算
        for (int i = 0; i <= min(n, MAXN-1); i++)
        {
            if (m >= i)
            {
                // 如果m大于等于i，则这一行所有元素都要计算
                count += row_count[i];
            }
            else
            {
                // 否则只计算前m+1个元素
                for (int j = 0; j <= m; j++)
                {
                    if (C[i][j] == 0)
                    {
                        count++;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}