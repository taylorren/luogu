#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        double a;
        int t;
        cin >> a >> t;

        for (int j = 1; j <= t; j++)
        {
            int digit = floor(a * j);
            result ^= digit;
        }
    }

    cout << result;
    return 0;
}