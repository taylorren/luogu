#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 9901;

// 快速幂
ll modpow(ll base, ll exp)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

// 计算等比数列和
ll geo_sum(ll p, ll exp)
{
    if (p == 1)
        return 1;
    return (modpow(p, exp + 1) - 1 + MOD) % MOD * modpow(p - 1, MOD - 2) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;

    // 特殊处理 b = 1 的情况
    if (b == 1)
    {
        ll ans = 0;  // 初始化为0而不是1
        for (ll i = 1; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                ans = (ans + i) % MOD;
                if (i != a / i)
                    ans = (ans + a / i) % MOD;
            }
        }
        cout << ans << endl;
        return 0;
    }

    ll ans = 1;

    // 对每个质因数计算贡献
    for (ll i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            int cnt = 0;
            while (a % i == 0)
            {
                a /= i;
                cnt++;
            }
            ans = ans * geo_sum(i, cnt * b) % MOD;
        }
    }

    // 处理剩余的质因数
    if (a > 1)
    {
        ans = ans * geo_sum(a, b) % MOD;
    }

    cout << ans << endl;

    return 0;
}