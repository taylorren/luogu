#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);  // 使用getline读取整行，包括空格

    int count = 0;
    for (char c : s)
    {
        // 只统计非空格和非换行符的字符
        if (c != ' ' && c != '\n')
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}