#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 大整数类，用于处理超出long long范围的数字
class BigInteger {
private:
    string digits; // 用字符串存储大整数，低位在前，高位在后

public:
    // 构造函数
    BigInteger(long long num = 0) {
        if (num == 0) {
            digits = "0";
        } else {
            while (num > 0) {
                digits.push_back(num % 10 + '0');
                num /= 10;
            }
        }
    }

    // 从字符串构造
    BigInteger(const string& s) {
        digits = s;
        reverse(digits.begin(), digits.end());
    }

    // 加法运算
    BigInteger operator+(const BigInteger& other) const {
        BigInteger result;
        result.digits = "";

        int carry = 0;
        int i = 0, j = 0;

        // 逐位相加
        while (i < digits.size() || j < other.digits.size() || carry) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i++] - '0';
            if (j < other.digits.size()) sum += other.digits[j++] - '0';

            result.digits.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        return result;
    }

    // 输出运算符重载
    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        string output = num.digits;
        reverse(output.begin(), output.end());
        return out << output;
    }
};

int main()
{
    int n;
    cin >> n;

    // 对于较大的n值，我们需要使用自底向上的动态规划方法
    // dp[i]表示爬上i阶楼梯的方法数
    vector<BigInteger> dp(n + 1);

    // 基本情况
    dp[0] = BigInteger(1);  // 爬0阶楼梯有1种方法(不动)
    dp[1] = BigInteger(1);  // 爬1阶楼梯有1种方法(走1步)

    // 填充dp表
    for (int i = 2; i <= n; i++)
    {
        // 要到达第i阶，我们可以：
        // 1. 从第i-1阶走1步
        // 2. 从第i-2阶走2步
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;

    return 0;
}
