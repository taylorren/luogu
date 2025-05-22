#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_LENGTH = 5001;

// 计算组合数C(n,k)，这里k只能是1或2
inline long long combination(long long n, int k) {
    if (k == 1) return n;
    return n * (n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> count(MAX_LENGTH, 0);
    int max_length = 0;
    
    // 读入木棒长度并统计
    for (int i = 0; i < n; ++i) {
        int length;
        cin >> length;
        count[length]++;
        max_length = max(max_length, length);
    }
    
    long long answer = 0;
    
    // 枚举两根相等的木棒长度
    for (int i = 1; i <= max_length; ++i) {
        if (count[i] < 2) continue;
        
        // 计算选择两根长度为i的木棒的方案数
        long long ways = combination(count[i], 2) % MOD;
        
        // 枚举另外两根木棒的长度组合
        for (int j = 1; j <= i / 2; ++j) {
            int k = i - j;
            
            if (j == k) {
                // 如果两根木棒长度相同
                if (count[j] >= 2) {
                    answer = (answer + ways * combination(count[j], 2)) % MOD;
                }
            } else {
                // 如果两根木棒长度不同
                if (count[j] > 0 && count[k] > 0) {
                    answer = (answer + ways * count[j] * count[k]) % MOD;
                }
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}