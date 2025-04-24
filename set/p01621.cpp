#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;

int parent[MAXN];

int find(int x)
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        parent[fx] = fy;
}

int main()
{
    int a, b, p;
    cin >> a >> b >> p;
    int n = b - a + 1;

    // 初始化并查集
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    // 埃氏筛法找质数
    vector<bool> is_prime(b + 1, true);
    for (int i = 2; i * i <= b; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= b; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    // 枚举所有大于等于p的质数
    for (int prime = p; prime <= b; ++prime)
    {
        if (!is_prime[prime])
            continue;
        // 找到区间内第一个prime的倍数
        int start = a;
        while (start % prime != 0)
            start++;
        for (int j = start + prime; j <= b; j += prime)
        {
            unite(start - a, j - a);
        }
    }

    // 统计集合数
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (find(i) == i)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}