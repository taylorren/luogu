#include <bits/stdc++.h>
using namespace std;
typedef long long ll, sb;
int a0, a1, b0, b1, ans = 0, n = 0;
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
int main()
{
    cin >> n;
    for (ll j = 1; j <= n; j++)
    {
        cin >> a0 >> a1 >> b0 >> b1;
        ans = 0;
        for (int i = 1; i * i <= b1; i++)
        {  // 一定是b1的因子，所以只要找到根号b1就可以了
            if (b1 % i == 0)
            {
                if (a1 == __gcd(a0, i) && b1 == lcm(i, b0))
                {  // 如果满足条件就加上
                    ans++;
                }
                if (a1 == __gcd(a0, b1 / i) && b1 == lcm(b1 / i, b0))
                {  // 平方的时候只算一次
                    if (b1 / i != i)
                        ans++;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}