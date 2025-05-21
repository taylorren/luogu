#include <bits/stdc++.h>
using namespace std;

// 反转整数字符串，去掉前导零
string reverseNum(string s, bool isDecimal = false) {
    if(s == "0") return s;
    
    long long num = 0;
    // 从右向左处理每一位
    for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] != '0' || num != 0) {  // 避免前导0
            num = num * 10 + (s[i] - '0');
        }
    }
    
    string result = to_string(num);
    // 如果是小数部分，需要去掉末尾的0
    if(isDecimal && result != "0") {
        while(result.back() == '0') {
            result.pop_back();
        }
    }
    return result;
}

int main()
{
    string s;
    cin >> s;

    if (s.find('/') != string::npos) {
        int pos = s.find('/');
        string num = s.substr(0, pos);
        string den = s.substr(pos + 1);
        cout << reverseNum(num) << "/" << reverseNum(den);
    }
    else if (s.find('.') != string::npos) {
        int pos = s.find('.');
        string intPart = s.substr(0, pos);
        string decPart = s.substr(pos + 1);
        // 小数部分特殊处理：传入isDecimal=true
        string revDec = reverseNum(decPart, true);
        if (revDec == "") revDec = "0";
        cout << reverseNum(intPart) << "." << revDec;
    }
    else if (s.find('%') != string::npos)
    {                  // 百分数
        s.pop_back();  // 去掉%
        cout << reverseNum(s) << "%";
    }
    else
    {  // 整数
        cout << reverseNum(s);
    }

    return 0;
}