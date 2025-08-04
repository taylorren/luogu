#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> counts(26, 0);
    string line;
    
    // 读取4行输入并统计字母频率
    for (int i = 0; i < 4; ++i) {
        getline(cin, line);
        for (char c : line) {
            if (c >= 'A' && c <= 'Z') {
                counts[c - 'A']++;
            }
        }
    }
    
    // 找到最大频率以确定柱状图高度
    int max_count = *max_element(counts.begin(), counts.end());
    
    // 绘制柱状图
    for (int i = max_count; i > 0; --i) {
        string row;
        for (int j = 0; j < 26; ++j) {
            if (counts[j] >= i) {
                if (!row.empty()) row += " ";
                row += "*";
            } else {
                if (!row.empty()) row += " ";
                row += " ";
            }
        }
        // 去除行末空格
        size_t last = row.find_last_not_of(' ');
        if (last != string::npos) {
            row = row.substr(0, last + 1);
        } else {
            row = "";
        }
        if (!row.empty()) cout << row << endl;
        
    }
    
    // 输出字母行
    string letters;
    for (int i = 0; i < 26; ++i) {
        if (!letters.empty()) letters += " ";
        letters += char('A' + i);
    }
    cout << letters << endl;
    
    return 0;
}