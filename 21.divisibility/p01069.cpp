#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 计算一个数的质因数分解
map<ll, int> factorize(ll n)
{
    map<ll, int> factors;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
    {
        factors[n]++;
    }
    return factors;
}

int main()
{
    int n;
    ll m1, m2;
    cin >> n >> m1 >> m2;

    vector<ll> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    // 分解m1的质因数
    auto m1_factors = factorize(m1);

    int min_time = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // 分解Si的质因数
        auto si_factors = factorize(s[i]);

        // 计算需要多少时间才能使细胞数量被M整除
        int max_time = 0;
        bool possible = true;

        for (auto& [prime, power_m1] : m1_factors)
        {
            int power_needed = power_m1 * m2;  // m1^m2中该质因子的总幂次

            // 查找Si中该质因子的幂次
            int power_si = 0;
            if (si_factors.count(prime) > 0)
            {
                power_si = si_factors[prime];
            }

            if (power_si == 0)
            {
                // Si中不包含这个质因子，无法整除M
                possible = false;
                break;
            }

            // 计算需要多少次分裂才能使Si^t中该质因子的幂次达到或超过power_needed
            int t = (power_needed + power_si - 1) / power_si;  // 向上取整
            max_time = max(max_time, t);
        }

        if (possible)
        {
            min_time = min(min_time, max_time);
        }
    }

    if (min_time == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_time << endl;
    }

    return 0;
}