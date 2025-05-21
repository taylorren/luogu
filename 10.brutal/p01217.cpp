#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// 判断一个数是否为回文数
bool isPalindrome(int n)
{
    string s = to_string(n);
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 判断一个数是否为质数
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // 优化：只需要检查到sqrt(n)
    int sqrtN = sqrt(n);
    for (int i = 5; i <= sqrtN; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;

    // 直接循环判断
    for (int i = a; i <= b; i++)
    {
        if((i>11&&i<99)||(i>999&&i<9999)||(i>99999&&i<999999)||(i>9999999&&i<99999999))
        {
            continue;
        }
        // 先判断是否回文
        if (isPalindrome(i))
        {
            // 再判断是否质数
            if (isPrime(i))
            {
                cout << i << endl;
            }
        }
    }

    return 0;
}