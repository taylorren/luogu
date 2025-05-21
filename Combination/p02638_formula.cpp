#include <iostream>
#include <vector>
using namespace std;

// 用vector实现高精度数
struct BigInt {
    vector<int> digits;
    
    BigInt(int x = 0) {
        if (x == 0) digits.push_back(0);
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
    }
    
    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.digits.resize(digits.size() + other.digits.size());
        
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < other.digits.size(); j++) {
                result.digits[i + j] += digits[i] * other.digits[j];
            }
        }
        
        for (int i = 0; i < result.digits.size() - 1; i++) {
            result.digits[i + 1] += result.digits[i] / 10;
            result.digits[i] %= 10;
        }
        
        while (result.digits.size() > 1 && result.digits.back() == 0) 
            result.digits.pop_back();
            
        return result;
    }
    
    BigInt operator+=(const BigInt& other) {
        int carry = 0;
        int i;
        for (i = 0; i < other.digits.size() || carry; i++) {
            if (i == digits.size()) digits.push_back(0);
            digits[i] += (i < other.digits.size() ? other.digits[i] : 0) + carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        return *this;
    }
};

// 计算组合数C(n,k)
BigInt C(int n, int k) {
    vector<BigInt> dp(k + 1, BigInt(0));
    dp[0] = BigInt(1);
    
    for(int i = 1; i <= n; i++) {
        for(int j = min(i, k); j > 0; j--) {
            dp[j] += dp[j-1];
        }
    }
    return dp[k];
}

// 计算g(n,i) - 即将i个相同的球放入n个盒子的方案数
BigInt g(int n, int i) {
    return C(i + n - 1, n - 1);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    BigInt ans(0);
    // 枚举放入0和1的个数
    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            ans += g(n, i) * g(n, j);
        }
    }
    
    // 输出结果
    for(int i = ans.digits.size() - 1; i >= 0; i--) {
        cout << ans.digits[i];
    }
    cout << endl;
    
    return 0;
}