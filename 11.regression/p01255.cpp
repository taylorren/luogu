#include <bits/stdc++.h>
using namespace std;

// 简化的大整数加法函数
string addStrings(const string& a, const string& b)
{
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    // 使用字符串数组存储斐波那契数列
    vector<string> dp(n + 1);

    // 基本情况
    dp[0] = "1";  // 爬0阶楼梯有1种方法(不动)
    if (n >= 1)
        dp[1] = "1";  // 爬1阶楼梯有1种方法(走1步)

    // 填充dp表
    for (int i = 2; i <= n; i++)
    {
        // 要到达第i阶，我们可以：
        // 1. 从第i-1阶走1步
        // 2. 从第i-2阶走2步
        dp[i] = addStrings(dp[i - 1], dp[i - 2]);
    }

    cout << dp[n] << endl;

    return 0;
}
