#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

// Remove leading zeros from string
string removeLeadingZeros(string s)
{
    int pos = s.find_first_not_of("0");
    if (pos == string::npos)
    {
        return "0";
    }
    return s.substr(pos);
}

// Remove trailing zeros from string
string removeTrailingZeros(string s)
{
    int pos = s.find_last_not_of("0");
    if (pos == string::npos)
    {
        return "0";
    }
    return s.substr(0, pos + 1);
}

int main()
{
    string s;
    cin >> s;

    // 处理小数
    if (s.find(".") != string::npos)
    {
        int pos = s.find(".");
        string whole = s.substr(0, pos);
        string decimal = s.substr(pos + 1, s.size());
        reverse(whole.begin(), whole.end());
        reverse(decimal.begin(), decimal.end());

        whole = removeLeadingZeros(whole);
        decimal = removeTrailingZeros(decimal);

        cout << whole << "." << decimal << endl;
    }
    else if (s.find("%") != string::npos)  // 百分数
    {
        s = s.substr(0, s.size() - 1);
        reverse(s.begin(), s.end());
        s = removeLeadingZeros(s);
        cout << s << "%" << endl;
    }
    else if (s.find("/") != string::npos)  // 分数
    {
        int pos = s.find("/");
        string numerator = s.substr(0, pos);
        string denominator = s.substr(pos + 1, s.size());
        reverse(numerator.begin(), numerator.end());
        reverse(denominator.begin(), denominator.end());

        numerator = removeLeadingZeros(numerator);
        denominator = removeLeadingZeros(denominator);

        cout << numerator << "/" << denominator << endl;
    }
    else  // regular number
    {
        reverse(s.begin(), s.end());
        s = removeLeadingZeros(s);
        cout << s << endl;
    }
}