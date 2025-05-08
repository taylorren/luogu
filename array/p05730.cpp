#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 定义0-9每个数字的点阵表示
    string digits[10][5] = {// 0
                            {"XXX", "X.X", "X.X", "X.X", "XXX"},
                            // 1
                            {"..X", "..X", "..X", "..X", "..X"},
                            // 2
                            {"XXX", "..X", "XXX", "X..", "XXX"},
                            // 3
                            {"XXX", "..X", "XXX", "..X", "XXX"},
                            // 4
                            {"X.X", "X.X", "XXX", "..X", "..X"},
                            // 5
                            {"XXX", "X..", "XXX", "..X", "XXX"},
                            // 6
                            {"XXX", "X..", "XXX", "X.X", "XXX"},
                            // 7
                            {"XXX", "..X", "..X", "..X", "..X"},
                            // 8
                            {"XXX", "X.X", "XXX", "X.X", "XXX"},
                            // 9
                            {"XXX", "X.X", "XXX", "..X", "XXX"}};

    int n;
    string number;

    // 读取输入
    cin >> n;
    cin >> number;

    // 逐行输出点阵
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 获取当前数字
            int digit = number[j] - '0';

            // 输出当前数字的第i行点阵
            cout << digits[digit][i];

            // 如果不是最后一个数字，输出一列间隔
            if (j < n - 1)
            {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}