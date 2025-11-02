#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    
    // 处理特殊情况
    if (n == 0) {
        cout << "0=0(base" << r << ")" << endl;
        return 0;
    }
    
    // 保存原始输入值
    int original_n = n;
    
    // 存储结果
    vector<char> digits;
    
    // 进行负进制转换
    while (n != 0) {
        int remainder = n % r;
        n = n / r;
        
        // 处理负余数的情况
        if (remainder < 0) {
            remainder += abs(r);
            n += 1;
        }
        
        // 将余数转换为对应的字符
        if (remainder < 10) {
            digits.push_back('0' + remainder);
        } else {
            digits.push_back('A' + remainder - 10);
        }
    }
    
    // 输出结果（从高位到低位）
    cout << original_n << "=";
    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i];
    }
    cout << "(base" << r << ")" << endl;
    
    return 0;
}