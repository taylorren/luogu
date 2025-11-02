#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;  // 足够存储1000!的位数

// 计算阶乘并统计数字出现次数
int countDigitInFactorial(int n, int digit)
{
    // 使用数组存储大整数，每个元素存储一位数字
    vector<int> factorial(MAXN, 0);
    factorial[0] = 1;  // 初始值为1
    int len = 1;       // 当前阶乘的位数

    // 计算阶乘
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;  // 进位

        // 对每一位进行乘法运算
        for (int j = 0; j < len; j++)
        {
            int product = factorial[j] * i + carry;
            factorial[j] = product % 10;  // 当前位的值
            carry = product / 10;         // 进位
        }

        // 处理最高位的进位
        while (carry > 0)
        {
            factorial[len] = carry % 10;
            carry /= 10;
            len++;
        }
    }

    // 统计指定数字出现的次数
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (factorial[i] == digit)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a;
        cin >> n >> a;

        int result = countDigitInFactorial(n, a);
        cout << result << endl;
    }

    return 0;
}