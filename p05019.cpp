#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> depths(n);
    for (int i = 0; i < n; i++)
    {
        cin >> depths[i];
    }

    int days = depths[0];  // 第一个位置的贡献

    // 计算其他位置的贡献
    for (int i = 1; i < n; i++)
    {
        if (depths[i] > depths[i - 1])
        {
            days += depths[i] - depths[i - 1];
        }
    }

    cout << days << endl;

    return 0;
}