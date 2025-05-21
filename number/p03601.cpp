#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
const int Max = 1e6 + 11;
const int mod = 666623333;
ll l, r, ans, cnt, is[Max + 10], prim[Max + 10], A[Max + 10], B[Max + 10];
inline void prep()
{
    for (int i = 2, j; i <= Max; ++i)
    {
        if (!is[i])
            prim[++cnt] = i;
        for (j = 1; j <= cnt && i * prim[j] <= Max; ++j)
        {
            is[i * prim[j]] |= 1;
            if (i % prim[j] == 0)
                break;
        }
    }
}
inline void solv()
{
    for (ll i = 1, p; prim[i] * prim[i] <= r; ++i)
    {
        p = prim[i];
        for (int x = (p - l % p) % p; x <= r - l; x += p)
        {
            A[x] /= p, A[x] *= p - 1;
            while (B[x] % p == 0)
                B[x] /= p;
        }
    }
}
int main()
{
    scanf("%lld%lld", &l, &r), prep();
    for (ll i = l; i <= r; ++i)
        A[i - l] = B[i - l] = i;
    solv();
    for (int i = 0; i <= r - l; ++i)
    {
        if (B[i] ^ 1)
            A[i] /= B[i], A[i] *= B[i] - 1;
        ans = (ans + i + l - A[i]) % mod;
    }
    return !printf("%lld\n", ans);
}