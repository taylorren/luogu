#include <iostream>
#include <string>
using namespace std;

// 判断一个数是否为质数
bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    
    // 统计每个字母出现的次数
    int count[26] = {0};
    for(char c : s) {
        count[c - 'a']++;
    }
    
    // 找出最大和最小出现次数
    int maxn = 0, minn = 100;
    for(int i = 0; i < 26; i++) {
        if(count[i] > 0) {
            maxn = max(maxn, count[i]);
            minn = min(minn, count[i]);
        }
    }
    
    // 判断差值是否为质数
    int diff = maxn - minn;
    if(isPrime(diff)) {
        cout << "Lucky Word" << endl;
        cout << diff << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    
    return 0;
}