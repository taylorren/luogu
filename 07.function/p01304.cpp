#include <iostream>
#include <vector>
using namespace std;

// 使用埃拉托色尼筛法生成素数表
vector<bool> sieve(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 和 1 不是素数
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// 验证哥德巴赫猜想
void goldbach_conjecture(int N) {
    // 生成素数表
    vector<bool> is_prime = sieve(N);

    // 遍历 4 到 N 的所有偶数
    for (int even = 4; even <= N; even += 2) {
        bool found = false;
        for (int p = 2; p <= even / 2; ++p) {
            if (is_prime[p] && is_prime[even - p]) {
                cout << even << "=" << p << "+" << even - p << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << even << " cannot be expressed as the sum of two primes." << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;

    if (N < 4 || N % 2 != 0) {
        cout << "Please enter an even number greater than or equal to 4." << endl;
    } else {
        goldbach_conjecture(N);
    }

    return 0;
}