#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int num;
    cin >> num;
    
    // 提取高16位和低16位
    unsigned int high = (num >> 16) & 0xFFFF;  // 右移16位，获取高16位
    unsigned int low = num & 0xFFFF;           // 与0xFFFF进行位与操作，获取低16位
    
    // 交换高低位
    unsigned int result = (low << 16) | high;  // 低位左移16位，与高位进行位或操作
    
    cout << result << endl;
    
    return 0;
}