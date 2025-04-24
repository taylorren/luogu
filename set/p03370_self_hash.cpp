#include <bits/stdc++.h>
using namespace std;

// 自定义哈希函数
unsigned long long getHash(const string& s) {
    unsigned long long hash = 0;
    const int base = 131; // 使用131作为基数
    const int mod = 1e9 + 7; // 使用大质数作为模数
    
    for (char c : s) {
        hash = (hash * base + c) % mod;
    }
    return hash;
}

int main() {
    int n;
    cin >> n;
    
    // 使用vector数组存储相同哈希值的字符串
    vector<vector<string>> hashTable(1000003); // 使用大质数作为表大小
    
    // 读入字符串并计算哈希值
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        unsigned long long hash = getHash(s);
        
        // 将字符串存入对应的哈希桶中
        int index = hash % 1000003;
        
        // 检查是否已存在相同字符串
        bool found = false;
        for (const string& str : hashTable[index]) {
            if (str == s) {
                found = true;
                break;
            }
        }
        
        // 如果是新字符串，则添加到对应的桶中
        if (!found) {
            hashTable[index].push_back(s);
        }
    }
    
    // 统计不同字符串的总数
    int count = 0;
    for (const auto& bucket : hashTable) {
        count += bucket.size();
    }
    
    cout << count << endl;
    return 0;
}