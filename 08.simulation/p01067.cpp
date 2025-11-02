#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;                         // 读取多项式的次数
    vector<int> coefficients(n + 1);  // 存储系数

    // 读取系数
    for (int i = 0; i <= n; ++i)
    {
        cin >> coefficients[i];
    }

    string result;  // 存储最终的多项式字符串

    for (int i = 0; i <= n; ++i)
    {
        int coeff = coefficients[i];
        int power = n - i;  // 当前项的指数

        if (coeff == 0)
            continue;  // 跳过系数为0的项

        // 处理符号
        if (result.empty())
        {
            // 如果是第一个非零项，直接添加
            if (coeff < 0)
            {
                result += "-";
                coeff = -coeff;  // 取绝对值
            }
        }
        else
        {
            // 不是第一个项，添加符号
            if (coeff > 0)
            {
                result += "+";
            }
            else
            {
                result += "-";
                coeff = -coeff;  // 取绝对值
            }
        }

        // 添加系数
        if (power == 0)
        {
            result += to_string(coeff);  // 0次项
        }
        else if (power == 1)
        {
            if (coeff == 1)
            {
                result += "x";  // 1次项
            }
            else
            {
                result += to_string(coeff) + "x";  // 1次项
            }
        }
        else
        {
            if (coeff == 1)
            {
                result += "x^" + to_string(power);  // 高次项
            }
            else
            {
                result += to_string(coeff) + "x^" + to_string(power);  // 高次项
            }
        }
    }

    cout << result << endl;  // 输出结果
    return 0;
}