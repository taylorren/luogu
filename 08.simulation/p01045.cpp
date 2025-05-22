#include <bits/stdc++.h>
using namespace std;

const int MAX_DIGITS = 500; // 最后500位

// 计算2^P-1的位数
int calculateDigits(int p) {
    // 2^P的位数 = P * log10(2) + 1 向下取整
    double digits = p * log10(2);
    return floor(digits) + 1;
}

// 大整数乘法，只保留最后MAX_DIGITS位
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> result(MAX_DIGITS, 0);
    
    for (int i = 0; i < MAX_DIGITS; i++) {
        for (int j = 0; j <= i; j++) {
            if (j < a.size() && (i-j) < b.size()) {
                result[i] += a[j] * b[i-j];
            }
        }
    }
    
    // 处理进位
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    
    return result;
}

// 快速幂计算2^P mod 10^MAX_DIGITS
vector<int> fastPowerMod(int p) {
    vector<int> result(MAX_DIGITS, 0);
    result[0] = 1; // 初始值为1
    
    vector<int> base(MAX_DIGITS, 0);
    base[0] = 2; // 基数为2
    
    while (p > 0) {
        if (p & 1) {
            // 如果p的二进制表示的当前位为1，乘以当前的base
            result = multiply(result, base);
        }
        
        // 计算下一个base（base = base * base）
        base = multiply(base, base);
        
        p >>= 1; // p除以2
    }
    
    return result;
}

int main() {
    int p;
    cin >> p;
    
    // 计算2^P-1的位数
    int numDigits = calculateDigits(p);
    cout << numDigits << endl;
    
    // 计算2^P mod 10^MAX_DIGITS
    vector<int> result = fastPowerMod(p);
    
    // 减1操作
    for (int i = 0; i < MAX_DIGITS; i++) {
        if (result[i] > 0) {
            result[i]--;
            break;
        } else {
            result[i] = 9;
        }
    }
    
    // 输出结果，每行50位，共10行
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            int idx = i * 50 + j;
            if (idx < MAX_DIGITS) {
                cout << result[MAX_DIGITS - 1 - idx];
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
    
    return 0;
}