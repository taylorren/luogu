#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 大整数类，用于处理超出long long范围的数字
class BigInteger
{
   private:
    string digits;  // 用字符串存储大整数，低位在前，高位在后

   public:
    // 构造函数
    BigInteger(long long num = 0)
    {
        if (num == 0)
        {
            digits = "0";
        }
        else
        {
            while (num > 0)
            {
                digits.push_back(num % 10 + '0');
                num /= 10;
            }
        }
    }

    // 从字符串构造
    BigInteger(const string& s)
    {
        digits = s;
        reverse(digits.begin(), digits.end());
    }

    // 加法运算
    BigInteger operator+(const BigInteger& other) const
    {
        BigInteger result;
        result.digits = "";

        int carry = 0;
        int i = 0, j = 0;

        // 逐位相加
        while (i < digits.size() || j < other.digits.size() || carry)
        {
            int sum = carry;
            if (i < digits.size())
                sum += digits[i++] - '0';
            if (j < other.digits.size())
                sum += other.digits[j++] - '0';

            result.digits.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        return result;
    }

    // 输出运算符重载
    friend ostream& operator<<(ostream& out, const BigInteger& num)
    {
        string output = num.digits;
        reverse(output.begin(), output.end());
        return out << output;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    // dp[i]表示从蜂房m到蜂房i的不同路线数量
    vector<BigInteger> dp(n + 1);

    // 基本情况：从m到m只有一条路径
    dp[m] = BigInteger(1);

    // 如果m+1在范围内，从m到m+1有一条路径
    if (m + 1 <= n)
    {
        dp[m + 1] = BigInteger(1);
    }

    // 填充dp表
    for (int i = m + 2; i <= n; i++)
    {
        // 要到达蜂房i，只能从蜂房i-1或i-2爬过来
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;

    return 0;
}
