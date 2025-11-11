#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 用bool数组，每个元素1字节，比int节省3/4空间
    bool lights[2000001] = {false};  // 所有灯初始为关

    for (int i = 1; i <= n; i++)
    {
        double a;
        int t;
        cin >> a >> t;

        for (int j = 1; j <= t; j++)
        {
            int digit = floor(a * j);
            lights[digit] = !lights[digit];  // 切换状态
        }
    }

    // 找到唯一开着的灯
    for (int i = 1; i <= 2000000; i++)
    {
        if (lights[i])
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
