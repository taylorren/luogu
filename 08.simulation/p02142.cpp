#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// return true if a >= b (both non-negative, no leading zeros)
bool ge(const string& a, const string& b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    return a >= b;  // lexicographical compare works for equal length
}

// a - b, assumes a >= b, both non-negative
string sub(const string& a, const string& b)
{
    string res;
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || borrow)
    {
        int x = (i >= 0 ? a[i] - '0' : 0);
        int y = (j >= 0 ? b[j] - '0' : 0);
        int d = x - y - borrow;
        if (d < 0)
        {
            d += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        res.push_back(d + '0');
        --i;
        --j;
    }
    // remove leading zeros
    while (res.size() > 1 && res.back() == '0')
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;

    if (ge(a, b))
    {
        cout << sub(a, b) << endl;
    }
    else
    {
        cout << "-" << sub(b, a) << endl;
    }
    return 0;
}
