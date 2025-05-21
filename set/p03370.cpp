#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 使用unordered_set来存储字符串，自动去重
    unordered_set<string> strings;

    // 读入n个字符串
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strings.insert(s);
    }

    // 输出不同字符串的数量
    cout << strings.size() << endl;

    return 0;
}