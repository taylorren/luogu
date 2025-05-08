#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> cuteness(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cuteness[i];
    }

    // 计算每只鱼左边有多少只鱼不如自己可爱
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (cuteness[j] < cuteness[i])
            {
                count++;
            }
        }
        cout << count;
        if (i < n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}