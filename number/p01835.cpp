#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 区间筛法求解区间 [L, R] 中的素数个数
int countPrimesInRange(ll L, ll R)
{
    // 特殊情况处理：如果 L <= 1，将 L 设为 2（因为1不是素数）
    L = max(2LL, L);

    // 区间长度
    int len = R - L + 1;

    // 标记数组，is_composite[i] 表示 L+i 是否为合数
    vector<bool> is_composite(len, false);

    // 找出 sqrt(R) 以内的所有素数
    int sqrt_R = sqrt(R);
    vector<int> small_primes;
    vector<bool> is_small_composite(sqrt_R + 1, false);

    // 埃氏筛法找出 sqrt(R) 以内的素数
    for (int i = 2; i <= sqrt_R; ++i)
    {
        if (!is_small_composite[i])
        {
            small_primes.push_back(i);
            for (int j = i * i; j <= sqrt_R; j += i)
            {
                is_small_composite[j] = true;
            }
        }
    }

    // 使用找到的素数筛选区间 [L, R] 内的合数
    for (int p : small_primes)
    {
        // 找出区间 [L, R] 中 p 的第一个倍数
        ll start = max((ll)p * p, (L + p - 1) / p * p);

        // 如果 start 小于 L，调整为下一个倍数
        if (start < L)
        {
            start += p;
        }

        // 标记 p 在区间 [L, R] 内的所有倍数为合数
        for (ll j = start; j <= R; j += p)
        {
            is_composite[j - L] = true;
        }
    }

    // 统计区间内的素数个数
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if (!is_composite[i])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll L, R;
    cin >> L >> R;

    cout << countPrimesInRange(L, R) << endl;

    return 0;
}