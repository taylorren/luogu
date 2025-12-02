
/*
 * P2461 [SDOI2008] 递归数列
 * 
 * 注意：虽然题目名称是"递归数列"，但不能用递归求解！
 * 
 * 问题定义：
 *   a[i] = c[1]*a[i-1] + c[2]*a[i-2] + ... + c[k]*a[i-k]  (i > k)
 *   求 sum(a[m] to a[n]) mod p，其中 n 可达 10^18
 * 
 * 解法：矩阵快速幂
 *   - 递归/记忆化搜索：会 TLE，无法处理 n=10^18
 *   - 矩阵快速幂：O(k³ log n)，可以处理超大的 n
 * 
 * 核心思路：
 *   1. 用矩阵表示线性递推关系
 *   2. 用快速幂计算 T^n（二进制幂运算）
 *   3. 用前缀和技巧：sum[m,n] = sum[1,n] - sum[1,m-1]
 * 
 * 时间复杂度：O(k³ log n)
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXK = 20;
int k;
long long p;
long long b[MAXK], c[MAXK];

// Matrix class for matrix exponentiation
struct Matrix {
    long long a[MAXK][MAXK];
    
    Matrix() {
        memset(a, 0, sizeof(a));
    }
    
    // Matrix multiplication
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < k + 1; i++) {
            for (int j = 0; j < k + 1; j++) {
                for (int t = 0; t < k + 1; t++) {
                    result.a[i][j] = (result.a[i][j] + a[i][t] * other.a[t][j]) % p;
                }
            }
        }
        return result;
    }
};

// Fast matrix exponentiation: compute mat^n
Matrix matPow(Matrix mat, long long n) {
    Matrix result;
    // Initialize result as identity matrix
    for (int i = 0; i < k + 1; i++) {
        result.a[i][i] = 1;
    }
    
    while (n > 0) {
        if (n & 1) {
            result = result * mat;
        }
        mat = mat * mat;
        n >>= 1;
    }
    return result;
}

// Calculate sum[1 to n]
long long getSum(long long n) {
    if (n <= 0) return 0;
    
    // For small n, calculate directly
    if (n <= k) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = (sum + b[i]) % p;
        }
        return sum;
    }
    
    // Build transition matrix
    // State: [a[i], a[i-1], ..., a[i-k+1], sum[i]]
    Matrix T;
    
    // First row: [c[1], c[2], ..., c[k], 0] - computes a[i+1]
    for (int i = 0; i < k; i++) {
        T.a[0][i] = c[i + 1] % p;
    }
    T.a[0][k] = 0;
    
    // Rows 1 to k-1: shift register (a[i] becomes a[i-1])
    for (int i = 1; i < k; i++) {
        T.a[i][i - 1] = 1;
    }
    
    // Last row: [c[1], c[2], ..., c[k], 1] - accumulates sum
    for (int i = 0; i < k; i++) {
        T.a[k][i] = c[i + 1] % p;
    }
    T.a[k][k] = 1;
    
    // Initial state vector: [a[k], a[k-1], ..., a[1], sum[k]]
    Matrix state;
    for (int i = 0; i < k; i++) {
        state.a[i][0] = b[k - i] % p;
    }
    long long sumK = 0;
    for (int i = 1; i <= k; i++) {
        sumK = (sumK + b[i]) % p;
    }
    state.a[k][0] = sumK;
    
    // Compute T^(n-k) * state
    Matrix result = matPow(T, n - k);
    result = result * state;
    
    return result.a[k][0];
}

int main() {
    cin >> k;
    
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    
    long long m, n;
    cin >> m >> n >> p;
    
    // sum[m to n] = sum[1 to n] - sum[1 to m-1]
    long long sumN = getSum(n);
    long long sumM = getSum(m - 1);
    
    long long answer = (sumN - sumM + p) % p;
    cout << answer << endl;
    
    return 0;
}