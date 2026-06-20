#include <bits/stdc++.h>
using namespace std;

vector<long long> calculated;

long long do_calc(int n)
{
    if (calculated[n] != -1)  // Already calculated
    {
        return calculated[n];
    }

    long long res = 1;

    for (int i = 1; i <= n / 2; i++)
    {
        res += do_calc(i);
    }

    calculated[n] = res;
    return res;
}
int main()
{
    int n;
    cin >> n;

    calculated.resize(n + 1, -1);  // Init to all -1
    long long res=do_calc(n);

    cout<<res<<endl;
    return 0;
}