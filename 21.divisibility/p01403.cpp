#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;

// Precompute divisor counts
ll f[MAXN];

void precompute() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            f[j]++;
        }
    }
    // Calculate prefix sum
    for (int i = 1; i < MAXN; i++) {
        f[i] += f[i-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precompute();
    
    int n;
    cin >> n;
    
    cout << f[n] << endl;
    
    return 0;
}