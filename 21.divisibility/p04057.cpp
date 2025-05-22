#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 计算最大公约数
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 计算最小公倍数
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;  // 先除后乘，避免溢出
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    // 计算三个数的最小公倍数
    ll result = lcm(lcm(a, b), c);

    cout << result << endl;

    return 0;
}