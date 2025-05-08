#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    vector<string> matrix;
    
    // 读取点阵图案
    while (cin >> line) {
        matrix.push_back(line);
    }
    
    int n = matrix.size(); // 点阵大小
    
    // 将二维点阵转换为一维序列
    string sequence;
    for (int i = 0; i < n; i++) {
        sequence += matrix[i];
    }
    
    // 计算压缩码
    vector<int> compressed;
    char current = '0'; // 从0开始
    int count = 0;
    
    for (char c : sequence) {
        if (c == current) {
            count++;
        } else {
            compressed.push_back(count);
            current = c;
            count = 1;
        }
    }
    
    // 添加最后一组
    if (count > 0) {
        compressed.push_back(count);
    }
    
    // 输出压缩码
    cout << n;
    for (int num : compressed) {
        cout << " " << num;
    }
    cout << endl;
    
    return 0;
}