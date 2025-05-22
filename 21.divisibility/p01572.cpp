#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 计算最大公约数
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 分数类
struct Fraction
{
    ll numerator;    // 分子
    ll denominator;  // 分母

    // 构造函数
    Fraction(ll num = 0, ll den = 1)
    {
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
        numerator = num;
        denominator = den;
        simplify();
    }

    // 化简分数
    void simplify()
    {
        if (numerator == 0)
        {
            denominator = 1;
            return;
        }

        ll g = gcd(abs(numerator), denominator);
        numerator /= g;
        denominator /= g;
    }

    // 分数加法
    Fraction operator+(const Fraction& other) const
    {
        ll lcm = denominator / gcd(denominator, other.denominator) *
                 other.denominator;
        ll num = numerator * (lcm / denominator) +
                 other.numerator * (lcm / other.denominator);
        return Fraction(num, lcm);
    }

    // 输出分数
    string toString() const
    {
        if (denominator == 1)
        {
            return to_string(numerator);
        }
        else
        {
            return to_string(numerator) + "/" + to_string(denominator);
        }
    }
};

// 读取分子或分母
ll readNumber(const string& expression, int& i)
{
    ll number = 0;
    while (i < expression.length() && isdigit(expression[i]))
    {
        number = number * 10 + (expression[i] - '0');
        i++;
    }
    return number;
}

// 读取一个分数
Fraction readFraction(const string& expression, int& i, char op)
{
    // 读取分子
    ll numerator = readNumber(expression, i);
    
    // 跳过分数线
    i++;
    
    // 读取分母
    ll denominator = readNumber(expression, i);
    
    // 根据运算符确定分子的符号
    if (op == '-')
    {
        numerator = -numerator;
    }
    
    return Fraction(numerator, denominator);
}

int main()
{
    string expression;
    cin >> expression;

    // 如果表达式不是以+或-开头，添加一个+号
    if (expression[0] != '+' && expression[0] != '-')
    {
        expression = "+" + expression;
    }

    // 读取第一个分数
    int i = 0;
    char op = expression[i++];
    Fraction result = readFraction(expression, i, op);
    
    // 处理剩余的分数
    while (i < expression.length())
    {
        // 读取运算符
        op = expression[i++];
        
        // 读取分数并直接计算结果
        Fraction frac = readFraction(expression, i, op);
        result = result + frac;
    }
    
    // 输出结果
    cout << result.toString() << endl;
    
    return 0;
}