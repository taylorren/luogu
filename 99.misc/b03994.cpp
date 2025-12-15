#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    long long c = 2 * n;
    long long s = 0;

    for (int i = 1; i <= n; i++)
    {
        c += 1ll * 2 * i;
        s += 1ll * i * i;
    }

    cout << c << endl << s;
}