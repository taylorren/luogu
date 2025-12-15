#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

int getRemainNumberLength(int remain)
{
    int len = 0;
    while (remain > 0)
    {
        remain /= 10;
        len++;
    }
    return len;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    int remain;
    // n = 1234
    // x = 4 -> 16 -> 6
    // remain = 123
    int result[MAX];
    bool found = false;
    int location;

    for (int i = 0; i < q; i++)
    {
        int x = n % 10;
        x = (x * x) % 10;
        remain = n / 10;

        if (x == 0)
        {
            n /= 10;
        }
        else
        {
            // remain有d位
            // x*(10^d)+remain
            // 新的数字构成
            int len = getRemainNumberLength(remain);
            n = x * pow(10, len) + remain;
        }

        result[i] = n;

        if (n == m)
        {
            found = true;
            location = i;
            break;
        }
    }

    if (!found)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i <= location; i++)
        {
            cout << result[i] << endl;
        }
    }
}