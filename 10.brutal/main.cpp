#include <bits/stdc++.h>
using namespace std;

const int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int cost(int x)
{
    if (x == 0)
        return stick[0];
    int s = 0;
    while (x)
    {
        s += stick[x % 10];
        x /= 10;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    int maxC = n - 4;
    vector<int> nums;
    const int LIMIT = 10000000;
    for (int x = 0; x <= LIMIT; ++x)
    {
        int c = cost(x);
        if (c <= maxC)
            nums.push_back(x);
    }
    unordered_map<int, int> costCache;
    for (int v : nums)
        costCache[v] = cost(v);
    long long ans = 0;
    for (int a : nums)
    {
        int ca = costCache[a];
        for (int b : nums)
        {
            int cb = costCache[b];
            int c = a + b;
            int cc = cost(c);
            if (ca + cb + cc + 4 == n)
                ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
