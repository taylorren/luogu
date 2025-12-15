#include <bits/stdc++.h>
using namespace std;

class HighPrecision
{
    friend istream& operator>>(istream& is, HighPrecision& hp);
    friend ostream& operator<<(ostream& os, const HighPrecision& hp);
    friend HighPrecision operator+(const HighPrecision& hp1,
                                   const HighPrecision& hp2);
    friend HighPrecision operator*(const HighPrecision& hp1,
                                   const HighPrecision& hp2);

   private:
    vector<int> num;

   public:
    HighPrecision() {}
    HighPrecision(const string& s)
    {
        for (int i = s.size() - 1; i >= 0; i--)
            num.push_back(s[i] - '0');
    }
    HighPrecision(int n) : HighPrecision(to_string(n)) {}

    vector<int> getNum() const
    {
        return num;
    }
};

istream& operator>>(istream& is, HighPrecision& hp)
{
    string s;
    is >> s;
    hp = HighPrecision(s);
    return is;
}

ostream& operator<<(ostream& os, const HighPrecision& hp)
{
    for (int i = hp.num.size() - 1; i >= 0; i--)
        os << hp.num[i];
    return os;
}

HighPrecision operator+(const HighPrecision& hp1, const HighPrecision& hp2)
{
    HighPrecision hp;
    int maxLen = max(hp1.num.size(), hp2.num.size());
    hp.num.resize(maxLen + 1, 0);

    for (int i = 0; i < maxLen; i++)
    {
        int a = (i < hp1.num.size()) ? hp1.num[i] : 0;
        int b = (i < hp2.num.size()) ? hp2.num[i] : 0;
        hp.num[i] += a + b;
        hp.num[i + 1] = hp.num[i] / 10;
        hp.num[i] %= 10;
    }

    if (hp.num.back() == 0 && hp.num.size() > 1)
    {
        hp.num.pop_back();
    }

    return hp;
}

HighPrecision operator*(const HighPrecision& hp1, const HighPrecision& hp2)
{
    HighPrecision hp;
    hp.num.resize(hp1.num.size() + hp2.num.size(), 0);

    for (int i = 0; i < hp1.num.size(); i++)
    {
        for (int j = 0; j < hp2.num.size(); j++)
        {
            hp.num[i + j] += hp1.num[i] * hp2.num[j];
            hp.num[i + j + 1] += hp.num[i + j] / 10;
            hp.num[i + j] %= 10;
        }
    }

    while (hp.num.size() > 1 && hp.num.back() == 0)
    {
        hp.num.pop_back();
    }

    return hp;
}

int main()
{
    int n;
    cin >> n;

    // 特殊情况处理
    if (n <= 3)
    {
        cout << n << endl << n << endl;
        return 0;
    }

    vector<int> result;

    // 从2开始选择连续的自然数
    int current = 2;
    int sum = 0;

    while (sum + current < n)
    {
        result.push_back(current);
        sum += current;
        current++;
    }

    // 计算超出的部分
    int diff = sum + current - n;

    if (diff == 0)
    {
        // 刚好等于n，加入最后一个数
        result.push_back(current);
    }
    else if (diff == 1)
    {
        // 超出1，去掉2，将最后一个数加1
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] == 2)
            {
                result.erase(result.begin() + i);
                break;
            }
        }
        result.push_back(current + 1);
    }
    else
    {
        // 超出diff，去掉等于diff的数，加入current
        // 根据数学证明，diff必定在[2,3,...,k]中，所以一定能找到
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] == diff)
            {
                result.erase(result.begin() + i);
                break;
            }
        }
        result.push_back(current);
    }

    // 按从小到大排序
    sort(result.begin(), result.end());

    // 最后统一计算乘积
    HighPrecision product("1");
    for (int num : result)
    {
        HighPrecision hp_num(num);
        product = product * hp_num;
    }

    // 输出结果
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl << product << endl;

    return 0;
}