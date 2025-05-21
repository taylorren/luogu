#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// 递归函数，将数字n表示为2的幂次方的和
string represent(int n)
{
    // 基本情况
    if (n == 0)
        return "0";
    if (n == 1)
        return "2(0)";
    if (n == 2)
        return "2";

    // 找出最高位的幂次
    int highestBit = 0;
    int temp = n;
    while (temp > 1)
    {
        temp >>= 1;
        highestBit++;
    }

    // 递归处理幂次
    string exponent;
    if (highestBit == 1)
    {
        exponent = "2";  // 2^1 简写为 2
    }
    else
    {
        exponent = "2(" + represent(highestBit) + ")";
    }
    
    // 计算2^highestBit
    int power = 1 << highestBit;

    // 递归处理剩余部分
    int remainder = n - power;
    if (remainder == 0)
    {
        return exponent;
    }
    else
    {
        return exponent + "+" + represent(remainder);
    }
}

int main()
{
    int n;
    cin >> n;

    cout << represent(n) << endl;

    return 0;
}