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

// Alternative implementation: push_back style with explicit carry variable
/*
HighPrecision operator+(const HighPrecision& hp1, const HighPrecision& hp2)
{
    HighPrecision hp;
    int carry = 0;
    int maxLen = max(hp1.num.size(), hp2.num.size());

    for (int i = 0; i < maxLen || carry; i++)
    {
        int sum = carry;
        if (i < hp1.num.size()) sum += hp1.num[i];
        if (i < hp2.num.size()) sum += hp2.num[i];

        hp.num.push_back(sum % 10);
        carry = sum / 10;
    }
    return hp;
}
*/

// Current implementation: pre-allocated array style
HighPrecision operator+(const HighPrecision& hp1, const HighPrecision& hp2)
{
    HighPrecision hp;
    int maxLen = max(hp1.num.size(), hp2.num.size());
    hp.num.resize(maxLen + 1, 0);  // Pre-allocate with extra space for carry

    for (int i = 0; i < maxLen; i++)
    {
        int a = (i < hp1.num.size()) ? hp1.num[i] : 0;
        int b = (i < hp2.num.size()) ? hp2.num[i] : 0;
        hp.num[i] += a + b;
        hp.num[i + 1] = hp.num[i] / 10;  // Carry to next position
        hp.num[i] %= 10;                 // Keep only the digit
    }

    // Remove leading zero if no final carry
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

    // Remove leading zero if no final carry
    while (hp.num.size() > 1 && hp.num.back() == 0)
    {
        hp.num.pop_back();
    }

    return hp;
}

int main()
{
    HighPrecision hp1, hp2;
    cin >> hp1 >> hp2;
    cout << hp1 * hp2 << endl;
    return 0;
}